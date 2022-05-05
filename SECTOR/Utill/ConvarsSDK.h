#pragma once

bool MemoryCompare(const BYTE* Data, const BYTE* Mask, const char* Size)
{
	for (; *Size; ++Size, ++Data, ++Mask)
	{
		if (*Size == 'x' && *Data != *Mask)
			return false;
	}

	return (*Size == NULL);
}


int FindSignature(int Start, int Size, const char* Pattern, const char* Mask)
{
	BYTE* Data = new BYTE[Size];
	SIZE_T BytesRead;

	ReadProcessMemory(GameAddres::Process, (LPVOID)Start, Data, Size, &BytesRead);

	for (DWORD i = 0; i < Size; i++)
	{
		if (MemoryCompare((const BYTE*)(Data + i), (const BYTE*)Pattern, Mask))
		{
			delete[] Data;
			return Start + i;
		}
	}

	delete[] Data;
	return NULL;
}


int GetStringHash(const char* Name)
{
	int ConvarNameHashTable = Memory::Read<DWORD>(FindSignature(GameAddres::VstdlibModule, GameAddres::VstdlibModuleSize, "\x8B\x3C\x85", "xxx") + 3) - GameAddres::VstdlibModule;

	int Codes[256];
	Memory::ReadVM(GameAddres::VstdlibModule + ConvarNameHashTable, &Codes);

	int V2 = 0;
	int V3 = 0;

	for (int i = 0; i < strlen(Name); i += 2)
	{
		V3 = Codes[V2 ^ toupper(Name[i])];

		if (i + 1 == strlen(Name))
			break;

		V2 = Codes[V3 ^ toupper(Name[i + 1])];
	}

	return V2 | (V3 << 8);
}


DWORD GetConVarAddres(const char* Name)
{
	int Hash = GetStringHash(Name);

	int InterfaceEngineCvar = Memory::Read<DWORD>(FindSignature(GameAddres::VstdlibModule, GameAddres::VstdlibModuleSize, "\x8B\x0D\x00\x00\x00\x00\xC7\x05", "xx????xx") + 0x2) - GameAddres::VstdlibModule;
	int CvarEngine = Memory::Read<DWORD>(GameAddres::VstdlibModule + InterfaceEngineCvar);
	int Pointer = Memory::Read<DWORD>(Memory::Read<DWORD>(CvarEngine + 0x34) + ((BYTE)Hash * 4));

	while (Pointer)
	{
		if (Memory::Read<DWORD>(Pointer) == Hash)
		{
			DWORD ConVarPointer = Memory::Read<DWORD>(Pointer + 0x4);

			char* VarName[32];
			Memory::ReadVM(Memory::Read<DWORD>(ConVarPointer + 0xC), &VarName);

			if (!strcmp((char*)VarName, Name))
				return ConVarPointer;
				
		}

		Pointer = Memory::Read<DWORD>(Pointer + 0xC);
	}

	return 0;
}


void SetValueFLOAT(const char* Name, float Value)
{
	int Addres = GetConVarAddres(Name);
	Memory::Write<int>(Addres + 0x2C, *(int*)&Value ^ Addres);
}


void SetValueINT(const char* Name, float Value)
{
	int Addres = GetConVarAddres(Name);
	Memory::Write<int>(Addres + 0x30, *(int*)&Value ^ Addres);
}