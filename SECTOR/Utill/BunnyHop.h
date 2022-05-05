#pragma once

namespace BunnyHopSetting
{
	bool Status = false;
}


void BunnyHop()
{
	while (BunnyHopSetting::Status)
	{
		if (Addres::GameIsActive)
		{
			if (Addres::LocalPlayer && GetAsyncKeyState(VK_SPACE))
			{
				if (Addres::MouseState == Offset::dwMouseIndexActive)
				{
					int LocalPlayerFlag = Memory::Read<int>(Addres::LocalPlayer + Offset::m_fFlags);

					if (LocalPlayerFlag == 257 || LocalPlayerFlag == 263)
					{
						Memory::Write<int>(GameAddres::Client + Offset::dwForceJump, 6);
					}
				}
			}
		}

		Sleep(0.2f);
	}
}