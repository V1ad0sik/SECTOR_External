#pragma once;

namespace RenderSetting
{
	bool RenderIsStarted = false;
	bool BoxESP = false;

	bool TeamCheck = true;
	bool HP = false;
	bool Gun = false;
}


void BoxESP()
{
	ShowWindow(GameAddres::GameHandle, SW_MINIMIZE);
	ShowWindow(GameAddres::GameHandle, SW_NORMAL);

	forceinline::dx_overlay Overlay(L"Valve001", L"Counter-Strike: Global Offensive - Direct3D 9", false);
	SetWindowLong(Overlay.get_overlay_wnd(), GWL_EXSTYLE, GetWindowLong(Overlay.get_overlay_wnd(), GWL_EXSTYLE) | WS_EX_PALETTEWINDOW);

	MSG message;
	ZeroMemory(&message, sizeof(message));

	forceinline::dx_renderer render = Overlay.create_renderer();


	while (RenderSetting::RenderIsStarted)
	{
		if (PeekMessage(&message, Overlay.get_overlay_wnd(), NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		render.end_rendering();
		render.begin_rendering();

		Sleep(5);

		if (Addres::GameIsActive)
		{
			ShowWindow(GameAddres::GameHandle, SW_NORMAL);
			BringWindowToTop(Overlay.get_overlay_wnd());
		}

		else
		{
			ShowWindow(GameAddres::GameHandle, SW_MINIMIZE);
			Sleep(1000);
			continue;
		}


		if (Addres::LocalPlayer)
		{
			for (int i = 0; i < 31; i++)
			{
				EntityClass Entity = Addres::EntityList[i];

				if (Entity.Valid())
				{
					if (RenderSetting::TeamCheck && Entity.Teammate())
					{
						continue;
					}

					Vec2 EntityOriginPosWorldToScreen = SDK::WorldToScreen(Entity.OriginPos(), Addres::ViewMatrix);

					if (EntityOriginPosWorldToScreen.x > 0 && EntityOriginPosWorldToScreen.y > 0)
					{
						Vec3 EntityHeadPos = Entity.BonePos(8);
						Vec2 EntityHeadPosWorldToScreen = SDK::WorldToScreen(EntityHeadPos, Addres::ViewMatrix);

						if (EntityHeadPosWorldToScreen.x > 0 && EntityHeadPosWorldToScreen.y > 0)
						{
							int BarPos = 0;

							int Height = EntityOriginPosWorldToScreen.y - EntityHeadPosWorldToScreen.y;
							int Width = Height / 2;


							if (RenderSetting::BoxESP)
							{
								render.draw_outlined_rect(EntityHeadPosWorldToScreen.x - Width / 2, EntityHeadPosWorldToScreen.y, Width, Height, 0xFFFFFFFF);
							}


							if (RenderSetting::HP)
							{
								BarPos += 10;
								render.draw_text(ToolSDK::ConvertToWstring("HP: " + to_string(Entity.Health())), EntityHeadPosWorldToScreen.x, EntityOriginPosWorldToScreen.y + BarPos, 0xFFFFFFFF);
							}


							if (RenderSetting::Gun)
							{
								SDK::WeaponClass Weapon = Entity.ActiveWeapon();
								string GunName = Weapon.Name();

								if (Entity.Scoped())
								{
									GunName += " (SCOPED)";
								}

								BarPos += 10;
								render.draw_text(ToolSDK::ConvertToWstring("Gun: " + GunName), EntityHeadPosWorldToScreen.x, EntityOriginPosWorldToScreen.y + BarPos, 0xFFFFFFFF);
							}
						}
					}
				}
			}
		}
	}
}