#pragma once

namespace GameAddresSDK
{
	mutex Mutex;

	namespace Scan
	{
		void Low()
		{
			while (true)
			{
				Mutex.lock();

				Addres::LocalPlayer = Memory::Read<int>(GameAddres::Client + Offset::dwLocalPlayer);
				Addres::GlowManager = Memory::Read<int>(GameAddres::Client + Offset::dwGlowObjectManager);
				Addres::MyTeamList = Memory::Read<int>(Addres::LocalPlayer + Offset::m_iTeamNum);

				Addres::GameIsActive = ToolSDK::GameIsActrive();

				Mutex.unlock();
				Sleep(500);
			}
		}


		void Average()
		{
			while (true)
			{
				Mutex.lock();

				Addres::MouseState = Memory::Read<BYTE>(GameAddres::Client + Offset::dwMouseEnable);

				if (Addres::LocalPlayer)
				{
					SDK::GetViewMatrix();

					for (int i = 1; i < 32; i++)
					{
						EntityClass Entity = Memory::Read<int>(GameAddres::Client + Offset::dwEntityList + i * 0x10);

						if (!Entity.Dormant() && Entity.Health() > 0)
							Addres::EntityList[i] = Entity.EntityObject;

						else
							Addres::EntityList[i] = 0;
					}
				}

				Mutex.unlock();
				Sleep(20);
			}
		}
	}


	void StartScan()
	{
		Addres::EnginePoint = Memory::Read<int>(GameAddres::Engine + Offset::dwClientState);

		thread StartLowScan(Scan::Low);
		StartLowScan.detach();

		thread StartAverageScan(Scan::Average);
		StartAverageScan.detach();
	}
}
