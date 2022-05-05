#pragma once

namespace ChamsSetting
{
	bool Status = false;
	bool TeamCheck = true;

	float Color[3] = { 254, 255, 255 };
}


void Chams()
{
	while (ChamsSetting::Status)
	{
		if (Addres::LocalPlayer)
		{
			for (int i = 0; i < 31; i++)
			{
				EntityClass Entity = Addres::EntityList[i];

				if (Entity.Valid())
				{
					if (ChamsSetting::TeamCheck && Entity.Teammate())
					{
						continue;
					}

					Memory::Write<int>(Entity.EntityObject + Offset::m_clrRender, ChamsSetting::Color[0] * 255);
					Memory::Write<int>(Entity.EntityObject + Offset::m_clrRender + 0x1, ChamsSetting::Color[1] * 255);
					Memory::Write<int>(Entity.EntityObject + Offset::m_clrRender + 0x2, ChamsSetting::Color[2] * 255);
				}
			}
		}

		Sleep(100);
	}
}


void ChamsReset()
{
	if (Addres::LocalPlayer)
	{
		for (int i = 0; i < 31; i++)
		{
			EntityClass Entity = Addres::EntityList[i];

			if (Entity.Valid())
			{
				Memory::Write<int>(Addres::EntityList[i] + Offset::m_clrRender, 255);
				Memory::Write<int>(Addres::EntityList[i] + Offset::m_clrRender + 0x1, 255);
				Memory::Write<int>(Addres::EntityList[i] + Offset::m_clrRender + 0x2, 255);
			}
		}
	}
}