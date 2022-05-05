#pragma once


namespace GameAddres
{
    HANDLE Process;
    HWND GameHandle;

    DWORD Client, Engine;
    DWORD VstdlibModule, VstdlibModuleSize;


    DWORD GetLibAddres(const char* Name, DWORD ProcessID, bool SizeMod = false)
    {
        HANDLE Shapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, ProcessID);

        if (Shapshot != INVALID_HANDLE_VALUE)
        {
            MODULEENTRY32 ModEntry;
            ModEntry.dwSize = sizeof(ModEntry);

            if (Module32First(Shapshot, &ModEntry))
            {
                do
                {
                    if (!strcmp(ModEntry.szModule, Name))
                    {
                        CloseHandle(Shapshot);

                        if (SizeMod)
                            return (uintptr_t)ModEntry.modBaseSize;

                        else
                            return (uintptr_t)ModEntry.modBaseAddr;
                    }
                }

                while (Module32Next(Shapshot, &ModEntry));
            }
        }

        return 0;
    }


    DWORD GetProcessID(const char* ProcessName)
    {
        HANDLE Shanshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

        PROCESSENTRY32 ProcessInfo = {0};
        ProcessInfo.dwSize = sizeof(PROCESSENTRY32);

        while (Process32Next(Shanshot, &ProcessInfo))
        {
            if (_stricmp(ProcessName, ProcessInfo.szExeFile) == 0)
            {
                CloseHandle(Shanshot);
                return ProcessInfo.th32ProcessID;
            }
        }

        CloseHandle(Shanshot);
        return 0;
    }


    void GetGameAddres(const char* ProcessName, const char* ProcessWindowName)
    {
        DWORD ProcessID = GetProcessID(ProcessName);

        if (ProcessID)
        {
            GameHandle = FindWindowA(0, ProcessWindowName);

            Client = GetLibAddres("client.dll", ProcessID);
            Engine = GetLibAddres("engine.dll", ProcessID);

            VstdlibModule = GetLibAddres("vstdlib.dll", ProcessID);
            VstdlibModuleSize = GetLibAddres("vstdlib.dll", ProcessID, true);

            Process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
        }

        else
        {
            MessageBox(0, "Could not find process.", ProcessName, 0);
            exit(0);
        }
    }
}
