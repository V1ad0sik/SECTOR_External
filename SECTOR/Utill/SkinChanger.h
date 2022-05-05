#pragma once

namespace SkinChangerSetting
{
	bool Status = false;
}


void SkinChanger()
{
	while (SkinChangerSetting::Status)
	{
		if (Addres::LocalPlayer)
		{
			for (int i = 0; i < 8; i++)
			{
				int MyWeapon = Memory::Read<int>(Addres::LocalPlayer + Offset::m_hMyWeapons + (i - 1) * 0x4) & 0xFFF;
				int WaponAddres = Memory::Read<int>(GameAddres::Client + Offset::dwEntityList + (MyWeapon - 1) * 0x10);

				if (WaponAddres)
				{
					short WeaponID = Memory::Read<short>(WaponAddres + Offset::m_iItemDefinitionIndex);
					int WeaponOwner = Memory::Read<int>(WaponAddres + Offset::m_OriginalOwnerXuidLow);

					Memory::Write<int>(WaponAddres + Offset::m_iItemIDHigh, -1);
					Memory::Write<int>(WaponAddres + Offset::m_nFallbackPaintKit, SkinChangerSDK::GetWeaponSkin(WeaponID));
					Memory::Write<int>(WaponAddres + Offset::m_iAccountID, WeaponOwner);
					Memory::Write<int>(WaponAddres + Offset::m_nFallbackStatTrak, 1337);
				}
			}


			if (GetAsyncKeyState(VK_F6))
			{
				Memory::Write<int>(Addres::EnginePoint + 0x174, -1);
				Sleep(4);
			}
		}

		Sleep(0.02f);
	}
}
