#pragma once


namespace Variable
{
	namespace Skeleton
	{
		int Legs[] = { 75, 74, 73, 72, 0, 65, 66, 67, 68, 69 };
		int Arms[] = { 40, 39, 38, 7, 10, 11, 12 };
		int Spine[] = { 8, 7, 0 };
	}


	namespace NetWork
	{
		char UserID[64];
		char HWID[10240];

		int CheatVersion = 7;
	}

	namespace Security
	{
		bool IsChecked = false;
	}
}