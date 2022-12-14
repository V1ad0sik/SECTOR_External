#pragma once

#include "Game.h"
#include "FindPattern.h"

namespace Dumper
{
	void Signatures()
	{
        DWORD processID = getProcessID("csgo.exe");

        Game::GameAddres::GetGameAddres("csgo.exe");

        procesHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);

        MODULEENTRY32 client = getGameModule("client.dll", processID);
        MODULEENTRY32 engine = getGameModule("engine.dll", processID);

        auto client_bytes = new DWORD[client.modBaseSize];
        DWORD client_bytes_read;

        ReadProcessMemory(procesHandle, client.modBaseAddr, client_bytes, client.modBaseSize, &client_bytes_read);

        if (client_bytes_read != client.modBaseSize) throw;

        auto engine_bytes = new DWORD[engine.modBaseSize];
        DWORD engine_bytes_read;

        ReadProcessMemory(procesHandle, engine.modBaseAddr, engine_bytes, engine.modBaseSize, &engine_bytes_read);

        if (engine_bytes_read != engine.modBaseSize)
            throw;

        Offset::dwLocalPlayer = patternScan(client, client_bytes, "8D 34 85 ? ? ? ? 89 15 ? ? ? ? 8B 41 08 8B 48 04 83 F9 FF", 4, 3);
        Offset::dwEntityList = patternScan(client, client_bytes, "BB ? ? ? ? 83 FF 01 0F 8C ? ? ? ? 3B F8", 0, 1);
        Offset::dwGlowObjectManager = patternScan(client, client_bytes, "A1 ? ? ? ? A8 01 75 4B", 4, 1);
        Offset::dwClientState = patternScan(engine, engine_bytes, "A1 ? ? ? ? 33 D2 6A 00 6A 00 33 C9 89 B0", 0, 1);
        Offset::dwClientState_ViewAngles = patternScan(engine, engine_bytes, "F3 0F 11 86 ? ? ? ? F3 0F 10 44 24 ? F3 0F 11 86", 0, 4, false);
        Offset::dwForceAttack = patternScan(client, client_bytes, "89 0D ? ? ? ? 8B 0D ? ? ? ? 8B F2 8B C1 83 CE 04", 0, 2);
        Offset::model_ambient_min = patternScan(engine, engine_bytes, "F3 0F 10 0D ? ? ? ? F3 0F 11 4C 24 ? 8B 44 24 20 35 ? ? ? ? 89 44 24 0C", 0, 4);
        Offset::dwMouseEnable = patternScan(client, client_bytes, "B9 ? ? ? ? FF 50 34 85 C0 75 10", 48, 1);
        Offset::dwForceJump = patternScan(client, client_bytes, "8B 0D ? ? ? ? 8B D6 8B C1 83 CA 02", 0, 2);
        Offset::dwViewMatrix = patternScan(client, client_bytes, "0F 10 05 ? ? ? ? 8D 85 ? ? ? ? B9", 176, 3);
        Offset::m_bDormant = patternScan(client, client_bytes, "8A 81 ? ? ? ? C3 32 C0", 8, 2, false);

        Offset::dwMouseIndexActive = Memory::Read<BYTE>(Game::GameAddres::Client + Offset::dwMouseEnable) + 1;
	}


    void NetVars()
    {
        const char* File = "Hazedumper.json";

        if (!URLDownloadToFile(NULL, "https://raw.githubusercontent.com/frk1/hazedumper/master/csgo.json", File, 0, 0))
        {
            ifstream Address(File);

            if (Address.is_open())
            {
                json Hazedumper = json::parse(Address);

                Offset::m_iGlowIndex = Hazedumper["netvars"]["m_iGlowIndex"];
                Offset::m_iTeamNum = Hazedumper["netvars"]["m_iTeamNum"];
                Offset::m_iHealth = Hazedumper["netvars"]["m_iHealth"];
                Offset::m_vecOrigin = Hazedumper["netvars"]["m_vecOrigin"];
                Offset::m_dwBoneMatrix = Hazedumper["netvars"]["m_dwBoneMatrix"];
                Offset::m_vecViewOffset = Hazedumper["netvars"]["m_vecViewOffset"];
                Offset::m_aimPunchAngle = Hazedumper["netvars"]["m_aimPunchAngle"];
                Offset::m_iShotsFired = Hazedumper["netvars"]["m_iShotsFired"];
                Offset::m_clrRender = Hazedumper["netvars"]["m_clrRender"];
                Offset::m_bUseCustomAutoExposureMax = Hazedumper["netvars"]["m_bUseCustomAutoExposureMax"];
                Offset::m_bUseCustomAutoExposureMin = Hazedumper["netvars"]["m_bUseCustomAutoExposureMin"];
                Offset::m_flCustomAutoExposureMax = Hazedumper["netvars"]["m_flCustomAutoExposureMax"];
                Offset::m_flCustomAutoExposureMin = Hazedumper["netvars"]["m_flCustomAutoExposureMin"];
                Offset::m_iDefaultFOV = Hazedumper["netvars"]["m_iDefaultFOV"];
                Offset::m_iCrosshairId = Hazedumper["netvars"]["m_iCrosshairId"];
                Offset::m_hMyWeapons = Hazedumper["netvars"]["m_hMyWeapons"];
                Offset::m_iItemDefinitionIndex = Hazedumper["netvars"]["m_iItemDefinitionIndex"];
                Offset::m_OriginalOwnerXuidLow = Hazedumper["netvars"]["m_OriginalOwnerXuidLow"];
                Offset::m_iItemIDHigh = Hazedumper["netvars"]["m_iItemIDHigh"];
                Offset::m_nFallbackPaintKit = Hazedumper["netvars"]["m_nFallbackPaintKit"];
                Offset::m_iAccountID = Hazedumper["netvars"]["m_iAccountID"];
                Offset::m_nFallbackStatTrak = Hazedumper["netvars"]["m_nFallbackStatTrak"];
                Offset::m_nFallbackSeed = Hazedumper["netvars"]["m_nFallbackSeed"];
                Offset::m_fFlags = Hazedumper["netvars"]["m_fFlags"];
                Offset::m_bSpotted = Hazedumper["netvars"]["m_bSpotted"];
                Offset::m_flFlashMaxAlpha = Hazedumper["netvars"]["m_flFlashMaxAlpha"];
                Offset::m_hActiveWeapon = Hazedumper["netvars"]["m_hActiveWeapon"];
                Offset::m_bIsScoped = Hazedumper["netvars"]["m_bIsScoped"];
                Offset::m_hViewModel = Hazedumper["netvars"]["m_hViewModel"];
                Offset::m_nModelIndex = 600;
            }

            Address.close();
            remove(File);
        }
    }
}