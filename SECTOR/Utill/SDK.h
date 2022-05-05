#pragma once

namespace SDK
{
	class WeaponClass
	{
		public: int Item = NULL;

		public:
			WeaponClass(int WeaponID)
			{
				Item = WeaponID;
			}


			bool IsGun()
			{
				switch (Item)
				{
					case 1: return true;
					case 2: return true;
					case 3: return true;
					case 4: return true;
					case 7: return true;
					case 8: return true;
					case 9: return true;
					case 10: return true;
					case 11: return true;
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
					case 38: return true;
					case 39: return true;
					case 40: return true;
					case 60: return true;
					case 61: return true;
					case 63: return true;
					case 64: return true;

					default: return false;
				}
			}


			bool IsKnife()
			{
				return Item == 42 || Item == 59;
			}


			bool IsPistol()
			{
				switch (Item)
				{
					case 1: return true;
					case 2: return true;
					case 3: return true;
					case 4: return true;
					case 30: return true;
					case 32: return true;
					case 36: return true;
					case 61: return true;

					default: return false;
				}
			}


			string Name()
			{
				switch (Item)
				{
					case 1: return "Desert Eagle";
					case 2: return "Dual Berettas";
					case 3: return "Five-SeveN";
					case 4: return "Glock-18";
					case 7: return "AK-47";
					case 8: return "AK-47";
					case 9: return "AWP";
					case 10: return "FAMAS";
					case 11: return "G3SG1";
					case 13: return "Galil AR";
					case 14: return "M249";
					case 16: return "M4A4";
					case 17: return "MAC-10";
					case 19: return "P90";
					case 20: return "Castle";
					case 23: return "MP5-SD";
					case 24: return "UMP-45";
					case 25: return "XM1014";
					case 26: return "PP-Bizon";
					case 27: return "MAG-7";
					case 28: return "Negev";
					case 29: return "Sawed-Off";
					case 30: return "Tec-9";
					case 31: return "Zeus";
					case 32: return "P2000";
					case 33: return "MP7";
					case 34: return "MP9";
					case 35: return "Nova";
					case 36: return "P250";
					case 37: return "Shild";
					case 38: return "SCAR-20";
					case 39: return "SG 553";
					case 40: return "SSG 08";
					case 41: return "Knife";
					case 42: return "Knife";
					case 43: return "Flashbang";
					case 44: return "Grenade";
					case 45: return "Smoke";
					case 46: return "Molotov";
					case 47: return "Decoy";
					case 48: return "Incendiary";
					case 49: return "Ñ4";
					case 59: return "Knife";
					case 60: return "M4A1-S";
					case 61: return "USP-S";
					case 63: return "CZ75-Auto";
					case 64: return "Revolver";
					case 500: return "Knife";
					case 503: return "Knife";
					case 505: return "Knife";
					case 506: return "Knife";
					case 507: return "Knife";
					case 508: return "Knife";
					case 509: return "Knife";
					case 512: return "Knife";
					case 514: return "Knife";
					case 515: return "Knife";
					case 516: return "Knife";
					case 517: return "Knife";
					case 518: return "Knife";
					case 519: return "Knife";
					case 520: return "Knife";
					case 521: return "Knife";
					case 522: return "Knife";
					case 523: return "Knife";
					case 525: return "Knife";

					default: return "Unknown";
				}
			}
	};


	Vec2 GetAngle(Vec3 LocalPlayerPos, Vec3 EntityPos)
	{
		Vec2 BonePos;
		Vec3 Delta;

		Delta.x = EntityPos.x - LocalPlayerPos.x;
		Delta.y = EntityPos.y - LocalPlayerPos.y;
		Delta.z = EntityPos.z - LocalPlayerPos.z;

		float DeltaVectorLength = sqrt(Delta.x * Delta.x + Delta.y * Delta.y + Delta.z * Delta.z);

		BonePos.x = -asin(Delta.z / DeltaVectorLength) * 57.28;
		BonePos.y = atan2(Delta.y, Delta.x) * 57.28;

		return BonePos;
	}


	float GetDistanceFromCenter(Vec2 BonePos, Vec2 WindowScreen, int Fov)
	{
		Vec2 Destance;

		Destance.x = BonePos.x - (WindowScreen.x / 2);
		Destance.y = BonePos.y - (WindowScreen.y / 2);

		return Fov * Fov - (Destance.x * Destance.x + Destance.y * Destance.y);
	}


	Vec2 WorldToScreen(Vec3 BonePos, float ViewMatrix[16])
	{
		VecMatrix Matrix;
		Vec2 NDC, BonePosWTS;

		Matrix.x = BonePos.x * ViewMatrix[0] + BonePos.y * ViewMatrix[1] + BonePos.z * ViewMatrix[2] + ViewMatrix[3];
		Matrix.y = BonePos.x * ViewMatrix[4] + BonePos.y * ViewMatrix[5] + BonePos.z * ViewMatrix[6] + ViewMatrix[7];
		Matrix.w = BonePos.x * ViewMatrix[12] + BonePos.y * ViewMatrix[13] + BonePos.z * ViewMatrix[14] + ViewMatrix[15];

		if (Matrix.w > 0.001)
		{
			NDC.x = Matrix.x / Matrix.w;
			NDC.y = Matrix.y / Matrix.w;

			BonePosWTS.x = (Addres::WindowScreen.x / 2 * NDC.x) + (NDC.x + Addres::WindowScreen.x / 2);
			BonePosWTS.y = -(Addres::WindowScreen.y / 2 * NDC.y) + (NDC.y + Addres::WindowScreen.y / 2);

			return BonePosWTS;
		}

		else
		{
			BonePosWTS.x = 0;
			BonePosWTS.y = 0;

			return BonePosWTS;
		}
	}


	void GetViewMatrix()
	{
		Addres::ViewMatrix[0] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 0);
		Addres::ViewMatrix[1] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 4);
		Addres::ViewMatrix[2] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 8);
		Addres::ViewMatrix[3] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 12);
		Addres::ViewMatrix[4] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 16);
		Addres::ViewMatrix[5] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 20);
		Addres::ViewMatrix[6] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 24);
		Addres::ViewMatrix[7] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 28);
		Addres::ViewMatrix[12] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 48);
		Addres::ViewMatrix[13] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 52);
		Addres::ViewMatrix[14] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 56);
		Addres::ViewMatrix[15] = Memory::Read<float>(GameAddres::Client + Offset::dwViewMatrix + 60);
	}


	Color GetColorFromEntityHP(int EntityHP)
	{
		Color Color;

		if (EntityHP >= 60)
		{
			Color.R = 0; Color.G = 255; Color.B = 0;
		}

		else if (EntityHP < 60 && EntityHP >= 25)
		{
			Color.R = 255; Color.G = 255; Color.B = 0;
		}

		else if (EntityHP < 25)
		{
			Color.R = 255; Color.G = 0; Color.B = 0;
		}

		return Color;
	}
}