#pragma once

namespace RadarHackSetting
{
	bool Status = false;
}


void RadarHack()
{
	while (RadarHackSetting::Status)
	{
		EntityClass LocalPlayer = Addres::LocalPlayer;

		if (LocalPlayer.EntityObject)
		{
			for (int i = 0; i < 31; i++)
			{
				EntityClass Entity = Addres::EntityList[i];

				if (Entity.Valid() && Entity.Teammate())
				{
					Memory::Write<bool>(Addres::EntityList[i] + Offset::m_bSpotted, true);
				}
			}
		}

		Sleep(500);
	}
}


void RadarHackReset()
{
	if (Addres::LocalPlayer)
	{
		for (int i = 0; i < 32; i++)
		{
			EntityClass Entity = Addres::EntityList[i];

			if (Entity.Valid())
			{
				Memory::Write<bool>(Addres::EntityList[i] + Offset::m_bSpotted, false);
			}
		}
	}
}