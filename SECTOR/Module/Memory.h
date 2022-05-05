#pragma once


#define NT_SUCCESS(x) ((x) >= 0)

typedef NTSTATUS(NTAPI* _NtWriteVirtualMemory)(HANDLE ProcessHandle, PVOID BaseAddress, LPCVOID Buffer, ULONG NumberOfBytesToWrite, PULONG NumberOfBytesWritten);
_NtWriteVirtualMemory NtWriteVirtualMemory = (_NtWriteVirtualMemory)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtWriteVirtualMemory");

typedef NTSTATUS(NTAPI* _NtReadVirtualMemory)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToRead, PULONG NumberOfBytesRead);
_NtReadVirtualMemory NtReadVirtualMemory = (_NtReadVirtualMemory)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtReadVirtualMemory");


namespace Memory
{
	template <typename T>
	T Read(DWORD Addres)
	{
		T Buffer;
		ReadProcessMemory(GameAddres::Process, (LPVOID)Addres, &Buffer, sizeof(Buffer), 0);
		return Buffer;
	}

	template <typename T>
	void Write(DWORD Addres, T Value)
	{
		WriteProcessMemory(GameAddres::Process, (LPVOID)Addres, &Value, sizeof(Value), 0);
	}


	template <class dataType>
	void ReadVM(DWORD AddressToRead, dataType* ValueToRead)
	{
		DWORD OldProtect = 0;
		NTSTATUS Status = 0;

		VirtualProtectEx(GameAddres::Process, (PVOID)AddressToRead, sizeof(dataType), PAGE_EXECUTE_READWRITE, &OldProtect);
		Status = NtReadVirtualMemory(GameAddres::Process, PVOID(AddressToRead), ValueToRead, sizeof(dataType), 0);

		VirtualProtectEx(GameAddres::Process, (PVOID)AddressToRead, sizeof(dataType), OldProtect, NULL);
	}
}