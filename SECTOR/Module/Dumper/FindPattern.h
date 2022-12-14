#pragma once

DWORD patternScan(MODULEENTRY32 module, DWORD* arr, const char* pattern, int extra, int offset, bool relative = true)
{
    DWORD scan = 0x0;
    DWORD firstMatch = 0x0;

    const char* pat = pattern;

    for (DWORD pCur = (DWORD)arr; pCur < (DWORD)arr + module.modBaseSize; ++pCur)
    {
        if (!*pat)
        {
            scan = firstMatch;
            break;
        }

        if (*(uint8_t*)pat == '\?' || *(uint8_t*)pCur == ((((pat[0] & (~0x20)) >= 'A' && (pat[0] & (~0x20)) <= 'F') ? ((pat[0] & (~0x20)) - 'A' + 0xa) : ((pat[0] >= '0' && pat[0] <= '9') ? pat[0] - '0' : 0)) << 4 | (((pat[1] & (~0x20)) >= 'A' && (pat[1] & (~0x20)) <= 'F') ? ((pat[1] & (~0x20)) - 'A' + 0xa) : ((pat[1] >= '0' && pat[1] <= '9') ? pat[1] - '0' : 0))))
        {
            if (!firstMatch)
                firstMatch = pCur;


            if (!pat[2])
            {
                scan = firstMatch;
                break;
            }

            if (*(WORD*)pat == 16191 || *(uint8_t*)pat != '\?')
                pat += 3;


            else
                pat += 2;
        }

        else
        {
            pat = pattern;
            firstMatch = 0;
        }
    }

    if (!scan)
        return 0x0;

    DWORD read;
    ReadProcessMemory(procesHandle, (void*)(scan - (DWORD)arr + (DWORD)module.modBaseAddr + offset), &read, sizeof(read), NULL);

    if (relative)
        return read + extra - (DWORD)module.modBaseAddr;


    else
        return read + extra;
}