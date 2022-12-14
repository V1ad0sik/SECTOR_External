#pragma once

HANDLE procesHandle;

MODULEENTRY32 getGameModule(const char* name, DWORD process_ID)
{
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, process_ID);
    MODULEENTRY32 modEntry;

    if (hSnap != INVALID_HANDLE_VALUE)
    { 
        modEntry.dwSize = sizeof(modEntry);

        if (Module32First(hSnap, &modEntry))
        {
            do 
            {
                if (!strcmp(modEntry.szModule, name)) 
                {
                    CloseHandle(hSnap);
                    return modEntry;
                }
            } 
            
            while (Module32Next(hSnap, &modEntry));
        }
    }

    MODULEENTRY32 module = { -1 };
    return module;
}


DWORD getProcessID(const char* process_name)
{
    HANDLE snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    PROCESSENTRY32 pInfo = { 0 };
    pInfo.dwSize = sizeof(PROCESSENTRY32);

    while (Process32Next(snapShot, &pInfo))
    {
        if (_stricmp(process_name, pInfo.szExeFile) == 0)
        {
            CloseHandle(snapShot);
            return pInfo.th32ProcessID;
        }
    }

    CloseHandle(snapShot);

    return 0;
}


namespace Game
{
    namespace GameAddres
    {
        HANDLE Process;
        HWND GameHandle;

        DWORD Client, Engine;
        DWORD VstdlibModule, VstdlibModuleSize;


        DWORD GetLibAddres(const char* Name, DWORD ProcessID, bool SizeMod = false)
        {
            HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, ProcessID);

            if (hSnap != INVALID_HANDLE_VALUE)
            {
                MODULEENTRY32 modEntry;
                modEntry.dwSize = sizeof(modEntry);

                if (Module32First(hSnap, &modEntry))
                {
                    do
                    {
                        if (!strcmp(modEntry.szModule, Name))
                        {
                            CloseHandle(hSnap);

                            if (SizeMod)
                                return (uintptr_t)modEntry.modBaseSize;

                            else
                                return (uintptr_t)modEntry.modBaseAddr;
                        }
                    }

                    while (Module32Next(hSnap, &modEntry));
                }
            }
        }


        DWORD GetProcessID(const char* Name)
        {
            HANDLE snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

            PROCESSENTRY32 pInfo = { 0 };
            pInfo.dwSize = sizeof(PROCESSENTRY32);

            while (Process32Next(snapShot, &pInfo))
            {
                if (_stricmp(Name, pInfo.szExeFile) == 0)
                {
                    CloseHandle(snapShot);
                    return pInfo.th32ProcessID;
                }
            }

            CloseHandle(snapShot);
            return 0;
        }


        void GetGameAddres(const char* ProcessName)
        {
            DWORD ProcessID = GetProcessID(ProcessName);

            if (ProcessID)
            {
                Client = GetLibAddres("client.dll", ProcessID);
                Engine = GetLibAddres("engine.dll", ProcessID);

                Process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
            }
        }
    }
}