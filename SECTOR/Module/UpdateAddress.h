#pragma once

namespace Updater
{
	bool LoadFile()
	{
		return URLDownloadToFile(NULL, "https://raw.githubusercontent.com/frk1/hazedumper/master/csgo.json", "HazedumperAdress.json", 0, 0) == 0 ? true : false;
	}


	void Update()
	{
		if (LoadFile())
		{
			ifstream Adress("HazedumperAdress.json");

			if (Adress.is_open())
			{
				json HazedumperAdress = json::parse(Adress);

				Offset::dwLocalPlayer = HazedumperAdress["signatures"]["dwLocalPlayer"];
				Offset::dwEntityList = HazedumperAdress["signatures"]["dwEntityList"];
				Offset::dwGlowObjectManager = HazedumperAdress["signatures"]["dwGlowObjectManager"];
				Offset::dwClientState = HazedumperAdress["signatures"]["dwClientState"];
				Offset::dwClientState_ViewAngles = HazedumperAdress["signatures"]["dwClientState_ViewAngles"];
				Offset::model_ambient_min = HazedumperAdress["signatures"]["model_ambient_min"];
				Offset::dwMouseEnable = HazedumperAdress["signatures"]["dwMouseEnable"];
				Offset::dwForceAttack = HazedumperAdress["signatures"]["dwForceAttack"];
				Offset::dwForceJump = HazedumperAdress["signatures"]["dwForceJump"];
				Offset::dwViewMatrix = HazedumperAdress["signatures"]["dwViewMatrix"];
				Offset::dwbSendPackets = HazedumperAdress["signatures"]["dwbSendPackets"];
				Offset::m_bDormant = HazedumperAdress["signatures"]["m_bDormant"];

				Offset::dwMouseIndexActive = Memory::Read<BYTE>(GameAddres::Client + Offset::dwMouseEnable);


				Offset::m_iGlowIndex = HazedumperAdress["netvars"]["m_iGlowIndex"];
				Offset::m_iTeamNum = HazedumperAdress["netvars"]["m_iTeamNum"];
				Offset::m_iHealth = HazedumperAdress["netvars"]["m_iHealth"];
				Offset::m_vecOrigin = HazedumperAdress["netvars"]["m_vecOrigin"];
				Offset::m_dwBoneMatrix = HazedumperAdress["netvars"]["m_dwBoneMatrix"];
				Offset::m_vecViewOffset = HazedumperAdress["netvars"]["m_vecViewOffset"];
				Offset::m_aimPunchAngle = HazedumperAdress["netvars"]["m_aimPunchAngle"];
				Offset::m_iShotsFired = HazedumperAdress["netvars"]["m_iShotsFired"];
				Offset::m_clrRender = HazedumperAdress["netvars"]["m_clrRender"];
				Offset::m_bUseCustomAutoExposureMax = HazedumperAdress["netvars"]["m_bUseCustomAutoExposureMax"];
				Offset::m_bUseCustomAutoExposureMin = HazedumperAdress["netvars"]["m_bUseCustomAutoExposureMin"];
				Offset::m_flCustomAutoExposureMax = HazedumperAdress["netvars"]["m_flCustomAutoExposureMax"];
				Offset::m_flCustomAutoExposureMin = HazedumperAdress["netvars"]["m_flCustomAutoExposureMin"];
				Offset::m_iDefaultFOV = HazedumperAdress["netvars"]["m_iDefaultFOV"];
				Offset::m_iCrosshairId = HazedumperAdress["netvars"]["m_iCrosshairId"];
				Offset::m_hMyWeapons = HazedumperAdress["netvars"]["m_hMyWeapons"];
				Offset::m_iItemDefinitionIndex = HazedumperAdress["netvars"]["m_iItemDefinitionIndex"];
				Offset::m_OriginalOwnerXuidLow = HazedumperAdress["netvars"]["m_OriginalOwnerXuidLow"];
				Offset::m_iItemIDHigh = HazedumperAdress["netvars"]["m_iItemIDHigh"];
				Offset::m_nFallbackPaintKit = HazedumperAdress["netvars"]["m_nFallbackPaintKit"];
				Offset::m_iAccountID = HazedumperAdress["netvars"]["m_iAccountID"];
				Offset::m_nFallbackStatTrak = HazedumperAdress["netvars"]["m_nFallbackStatTrak"];
				Offset::m_nFallbackSeed = HazedumperAdress["netvars"]["m_nFallbackSeed"];
				Offset::m_fFlags = HazedumperAdress["netvars"]["m_fFlags"];
				Offset::m_bSpotted = HazedumperAdress["netvars"]["m_bSpotted"];
				Offset::m_flFlashMaxAlpha = HazedumperAdress["netvars"]["m_flFlashMaxAlpha"];
				Offset::m_hActiveWeapon = HazedumperAdress["netvars"]["m_hActiveWeapon"];
				Offset::m_bIsScoped = HazedumperAdress["netvars"]["m_bIsScoped"];
				Offset::m_hViewModel = HazedumperAdress["netvars"]["m_hViewModel"];
				Offset::m_nModelIndex = 600;
			}

			else
			{
				MessageBox(0, "Не удалось открыть файл 'HazedumperAdress.json'.", " ", 0);
				exit(0);
			}
				
		}

		else
		{
			MessageBox(0, "Не удалось получить файл с 'raw.githubusercontent.com/frk1/hazedumper/master/csgo.json'.", " ", 0);
			exit(0);
		}	
	}

	void Remove()
	{
		remove("HazedumperAdress.json");
	}
}
