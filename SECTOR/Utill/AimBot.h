#pragma once

namespace AimBotSetting
{
	bool Status = false;
	bool OnlyVisible = false;
	bool TeamCheck = true;
	bool Nearest = false;

	int Key = 6;
	int FOV = 160;
	int Smooth = 1;
	int Bone = 8;
}


int GetBestTarger()
{
	int BestTarget = 0;
	int OldDistance = -150000000;

	for (int i = 0; i < 31; i++)
	{
		EntityClass Entity = Addres::EntityList[i];

		if (Entity.Valid())
		{
			if (AimBotSetting::TeamCheck && Entity.Teammate() || (AimBotSetting::OnlyVisible && Entity.Visible()))
			{
				continue;
			}

			Vec2 EntityWorldToScreen = SDK::WorldToScreen(Entity.BonePos(AimBotSetting::Bone), Addres::ViewMatrix);

			if (EntityWorldToScreen.x > 0 && EntityWorldToScreen.y > 0)
			{
				float NewDistance = SDK::GetDistanceFromCenter(EntityWorldToScreen, Addres::WindowScreen, AimBotSetting::FOV);

				if (OldDistance < NewDistance && NewDistance > 0)
				{
					OldDistance = NewDistance;
					BestTarget = Entity.EntityObject;
				}
			}
		}
	}

	return BestTarget;
}


int GetBestBone(EntityClass Entity)
{
	int Bone[] = { 8, 6, 5, 4, 3, 0 };
	int OldDistance = -150000000;
	int BestBone = NULL;

	for (int i = 0; i < 6; i++)
	{
		Vec2 EntityWorldToScreen = SDK::WorldToScreen(Entity.BonePos(Bone[i]), Addres::ViewMatrix);

		if (EntityWorldToScreen.x > 0 && EntityWorldToScreen.y > 0)
		{
			float NewDistance = SDK::GetDistanceFromCenter(EntityWorldToScreen, Addres::WindowScreen, 180);

			if (OldDistance < NewDistance && NewDistance > 0)
			{
				OldDistance = NewDistance;
				BestBone = Bone[i];
			}
		}
	}

	return BestBone;
}


void AimBot()
{
	while (AimBotSetting::Status)
	{
		Sleep(0.02f);

		if (AimBotSetting::Key != 0)
		{
			if (!(GetAsyncKeyState(AimBotSetting::Key) && Addres::GameIsActive))
			{
				continue;
			}
		}

		EntityClass LocalPlayer = Addres::LocalPlayer;
		SDK::WeaponClass Weapon = LocalPlayer.ActiveWeapon();

		if (LocalPlayer.EntityObject && Weapon.IsGun())
		{
			EntityClass Entity = GetBestTarger();

			if (Entity.Valid())
			{
				EntityClass LocalPlayer = Addres::LocalPlayer;

				Vec2 BonePos, ViewAngle;

				if (AimBotSetting::Nearest)
					BonePos = SDK::GetAngle(LocalPlayer.OriginPosAIM(), Entity.BonePos(GetBestBone(Entity)));

				else
					BonePos = SDK::GetAngle(LocalPlayer.OriginPosAIM(), Entity.BonePos(AimBotSetting::Bone));


				ViewAngle.x = Memory::Read<float>(Addres::EnginePoint + Offset::dwClientState_ViewAngles);
				ViewAngle.y = Memory::Read<float>(Addres::EnginePoint + Offset::dwClientState_ViewAngles + 0x4);

				Memory::Write<float>(Addres::EnginePoint + Offset::dwClientState_ViewAngles, ViewAngle.x + ((BonePos.x - ViewAngle.x) / AimBotSetting::Smooth));
				Memory::Write<float>(Addres::EnginePoint + Offset::dwClientState_ViewAngles + 0x4, ViewAngle.y + ((BonePos.y - ViewAngle.y) / AimBotSetting::Smooth));
			}
		}
	}
}