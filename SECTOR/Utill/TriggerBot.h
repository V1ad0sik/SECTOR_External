#pragma once

namespace TriggerBotSetting
{
	bool Status = false;
	bool TeamCheck = true;

	int Delay = 20;
	int Key = 6;
}


bool GunIsValidForTriggetBot(EntityClass LocalPlayer)
{
	switch (LocalPlayer.ActiveWeapon())
	{
		case 1: return true;
		case 2: return true;
		case 3: return true;
		case 4: return true;
		case 7: return true;
		case 8: return true;
		case 9: return LocalPlayer.Scoped();
		case 10: return true;
		case 11: return LocalPlayer.Scoped();
		case 13: return true;
		case 14: return true;
		case 16: return true;
		case 17: return true;
		case 19: return true;
		case 23: return true;
		case 24: return true;
		case 25: return true;
		case 26: return true;
		case 27: return true;
		case 28: return true;
		case 29: return true;
		case 30: return true;
		case 31: return true;
		case 32: return true;
		case 33: return true;
		case 34: return true;
		case 35: return true;
		case 36: return true;
		case 38: return LocalPlayer.Scoped();
		case 39: return true;
		case 40: return LocalPlayer.Scoped();
		case 60: return true;
		case 61: return true;
		case 63: return true;

		default: return false;
	}
}


bool GetTarget(EntityClass LocalPlayer)
{
	int EntityID = Memory::Read<int>(LocalPlayer.EntityObject + Offset::m_iCrosshairId);
	EntityClass Entity = Memory::Read<int>(GameAddres::Client + Offset::dwEntityList + (EntityID - 1) * 0x10);

	if (Entity.Valid())
	{
		if (TriggerBotSetting::TeamCheck && Entity.Teammate())
		{
			return false;
		}

		return EntityID > 0 && EntityID <= 64;
	}

	return false;
}


void TriggerBot()
{
	while (TriggerBotSetting::Status)
	{
		EntityClass LocalPlayer = Addres::LocalPlayer;

		if (LocalPlayer.EntityObject && GunIsValidForTriggetBot(LocalPlayer))
		{
			if (TriggerBotSetting::Key != 0)
			{
				if (!GetAsyncKeyState(TriggerBotSetting::Key))
				{
					continue;
				}
			}

			if (Addres::GameIsActive && GetTarget(LocalPlayer))
			{
				Sleep(TriggerBotSetting::Delay);

				if (GetTarget(LocalPlayer))
				{
					Memory::Write<int>(GameAddres::Client + Offset::dwForceAttack, 6);
				}
			}
		}

		Sleep(5);
	}
}