#pragma once

namespace NoFlashSetting
{
	bool Status = false;
	int Value = 0;
}


void NoFlash()
{
	while (NoFlashSetting::Status)
	{
		if (Addres::LocalPlayer)
		{
			Memory::Write<float>(Addres::LocalPlayer + Offset::m_flFlashMaxAlpha, NoFlashSetting::Value);
		}	

		Sleep(100);
	}
}


void NoFlashReset()
{
	if (Addres::LocalPlayer)
	{
		Memory::Write<float>(Addres::LocalPlayer + Offset::m_flFlashMaxAlpha, 255);
	}
}