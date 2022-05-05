#pragma once

namespace KnifeChangerSDK
{
	int ActiveWeapon = 0;

	namespace Models
	{
		const char* Knife[] =
		{
			"Bayonet",
			"M9 Bayonet",
			"Karambit",
			"Flip",
			"Gut",
			"Stiletto",
			"Huntsman",
			"Classic",
			"Falchion",
			"Navaja"
		};


		const char* KnifePath[] =
		{
			"models/weapons/v_knife_bayonet.mdl",
			"models/weapons/v_knife_m9_bay.mdl",
			"models/weapons/v_knife_karam.mdl",
			"models/weapons/v_knife_flip.mdl",
			"models/weapons/v_knife_gut.mdl",
			"models/weapons/v_knife_stiletto.mdl",
			"models/weapons/v_knife_tactical.mdl",
			"models/weapons/v_knife_css.mdl",
			"models/weapons/v_knife_falchion_advanced.mdl",
			"models/weapons/v_knife_gypsy_jackknife.mdl"
		};
	}


	int GetKnifeModelID(const char* Name)
	{
		int ClientState = Memory::Read<int>(GameAddres::Engine + Offset::dwClientState);

		int Strcut_1 = Memory::Read<int>(ClientState + 0x52A4);
		int Strcut_2 = Memory::Read<int>(Strcut_1 + 0x40);
		int Strcut_3 = Memory::Read<int>(Strcut_2 + 0xC);

		for (int i = 0; i < 4096; i++)
		{
			int Struct_3 = Memory::Read<int>(Strcut_3 + 0xC + i * 0x34);

			char Model[64] = { 0 };
			Memory::ReadVM(Struct_3, &Model);

			if (Model && _stricmp(Model, Name) == 0)
			{
				return i;
			}
		}

		return 0;
	}
}