#pragma once

namespace ToolSDK
{
	bool GameIsActrive()
	{
		return GetForegroundWindow() == GameAddres::GameHandle;
	}


	Vec2 GetWinScreen()
	{
		Vec2 WindowScreen;

		WindowScreen.x = GetSystemMetrics(SM_CXSCREEN);
		WindowScreen.y = GetSystemMetrics(SM_CYSCREEN);

		return WindowScreen;
	}


	wstring ConvertToWstring(const string Message)
	{
		wstring result(Message.begin(), Message.end());
		return result;
	}


	template<typename T, size_t Number>
	inline size_t GetArraySize(const T(&Array)[Number])
	{
		return Number;
	};


	int FindIndex(int Array[], int Value, int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			if (Array[i] == Value)
			{
				return i;
			}
		}

		return 0;
	}
}


namespace GetSectorPath
{
	string UserIDConfig()
	{
		return "data.json";
	}


	string ExeFile()
	{
		return "sector.exe";
	}


	string BatFile()
	{
		return "start.bat";
	}


	string Config()
	{
		return "Config";
	}


	string SkinConfig()
	{
		return Config() + (string)"\\Skin.json";
	}


	string CheatConfig()
	{
		return Config() + (string)"\\Setting.json";
	}
}