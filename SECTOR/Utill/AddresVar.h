#pragma once

namespace Addres
{
	int LocalPlayer = 0;
	int GlowManager = 0;
	int MyTeamList = 0;
	int MouseState = 0;

	int EntityList[32];
	int EntityGlowList[32];

	float ViewMatrix[16];

	int EnginePoint = 0;
	bool GameIsActive = false;

	Vec2 WindowScreen = ToolSDK::GetWinScreen();
}