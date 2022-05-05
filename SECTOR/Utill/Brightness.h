#pragma once

namespace BrightnessSetting
{
	bool Status = false;
	float Value = 100;
}


void Brightness()
{
	int ThisPtr = GameAddres::Engine + Offset::model_ambient_min - 0x2C;
	int Xored = *(int*)&BrightnessSetting::Value ^ ThisPtr;

	Memory::Write<int>(GameAddres::Engine + Offset::model_ambient_min, Xored);
}


void BrightnessReset()
{
	int Value = 0;

	int ThisPtr = GameAddres::Engine + Offset::model_ambient_min - 0x2C;
	int Xored = *(int*)&Value ^ ThisPtr;

	Memory::Write<int>(GameAddres::Engine + Offset::model_ambient_min, Xored);
}