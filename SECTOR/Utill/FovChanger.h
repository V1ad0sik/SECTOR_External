#pragma once

namespace FovChangerSetting
{
	bool Status = false;
	int Fov = 90;
}


void FovChanger()
{
	while (FovChangerSetting::Status)
	{
		if (Addres::LocalPlayer)
		{
			Memory::Write<int>(Addres::LocalPlayer + Offset::m_iDefaultFOV, FovChangerSetting::Fov);
		}

		Sleep(50);
	}
}


void SliderFovChanger()
{
	if (Addres::LocalPlayer)
	{
		Memory::Write<int>(Addres::LocalPlayer + Offset::m_iDefaultFOV, FovChangerSetting::Fov);
	}
}


void FovChangerReset()
{
	if (Addres::LocalPlayer)
	{
		Memory::Write<int>(Addres::LocalPlayer + Offset::m_iDefaultFOV, 90);
	}
}