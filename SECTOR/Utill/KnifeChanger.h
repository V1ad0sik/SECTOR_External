#pragma once

namespace KnifeChangerSetting
{
	bool Status = false;
}


void KnifeChanger()
{
	const char* KnifePath;
	int KnifeModelID = 0;

	KnifePath = KnifeChangerSDK::Models::KnifePath[KnifeChangerSDK::ActiveWeapon];
	KnifeModelID = KnifeChangerSDK::GetKnifeModelID(KnifePath);

	while (KnifeChangerSetting::Status)
	{
		EntityClass LocalPlayer = Addres::LocalPlayer;
		SDK::WeaponClass Weapon = LocalPlayer.ActiveWeapon();

		if (LocalPlayer.EntityObject && Weapon.IsKnife())
		{
			short ViewModel = Memory::Read<short>(Addres::LocalPlayer + Offset::m_hViewModel);
			int WaponAddres = Memory::Read<int>(GameAddres::Client + Offset::dwEntityList + (ViewModel - 1) * 0x10);

			Memory::Write<short>(WaponAddres + Offset::m_nModelIndex, KnifeModelID);

			if (GetAsyncKeyState(VK_F6))
			{
				KnifePath = KnifeChangerSDK::Models::KnifePath[KnifeChangerSDK::ActiveWeapon];
				KnifeModelID = KnifeChangerSDK::GetKnifeModelID(KnifePath);

				Memory::Write<int>(Addres::EnginePoint + 0x174, -1);
				Sleep(2);
			}
		}

		Sleep(0.02f);
	}
}