#pragma once

namespace AutoPistolSetting
{
	bool Status = false;
}


void AutoPistol()
{
	while (AutoPistolSetting::Status)
	{
		EntityClass LocalPlayer = Addres::LocalPlayer;
		SDK::WeaponClass Weapon = LocalPlayer.ActiveWeapon();

		if (GetAsyncKeyState(1) && Addres::GameIsActive && Addres::MouseState == Offset::dwMouseIndexActive && LocalPlayer.EntityObject && Weapon.IsPistol())
		{
			Memory::Write<int>(GameAddres::Client + Offset::dwForceAttack, 6);
		}	

		Sleep(25);
	}
}