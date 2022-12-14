//#pragma once
//
//namespace FakeLagSetting
//{
//	bool Status = false;
//	int Tick = 16;
//}
//
//
//void FakeLag()
//{
//	while (FakeLagSetting::Status)
//	{
//		Memory::Write<bool>(GameAddres::Engine + Offset::dwbSendPackets, false);
//		Sleep(FakeLagSetting::Tick);
//
//		Memory::Write<bool>(GameAddres::Engine + Offset::dwbSendPackets, true);
//		Sleep(FakeLagSetting::Tick);
//	}
//}