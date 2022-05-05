#pragma once

namespace NightModSetting
{
	bool Status = false;
	float Value = 1.0f;
}


void NightMod()
{
	while (NightModSetting::Status)
	{
		for (int i = 32; i < 2048; i++)
		{
			EntityClass Entity = Memory::Read<int>(GameAddres::Client + Offset::dwEntityList + i * 0x10);

			if (Entity.ClassID() == 69)
			{
				Memory::Write<int>(Entity.EntityObject + Offset::m_bUseCustomAutoExposureMin, 1);
				Memory::Write<int>(Entity.EntityObject + Offset::m_bUseCustomAutoExposureMax, 1);

				Memory::Write<float>(Entity.EntityObject + Offset::m_flCustomAutoExposureMin, NightModSetting::Value);
				Memory::Write<float>(Entity.EntityObject + Offset::m_flCustomAutoExposureMax, NightModSetting::Value);
			}
		}

		Sleep(500);
	}
}


void NightModrReset()
{
	for (int i = 32; i < 2048; i++)
	{
		EntityClass Entity = Memory::Read<int>(GameAddres::Client + Offset::dwEntityList + i * 0x10);

		if (Entity.ClassID() == 69)
		{
			Memory::Write<int>(Entity.EntityObject + Offset::m_bUseCustomAutoExposureMin, 1);
			Memory::Write<int>(Entity.EntityObject + Offset::m_bUseCustomAutoExposureMax, 1);

			Memory::Write<float>(Entity.EntityObject + Offset::m_flCustomAutoExposureMin, 1);
			Memory::Write<float>(Entity.EntityObject + Offset::m_flCustomAutoExposureMax, 1);
		}
	}
}


