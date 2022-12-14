#include "Module/Include.h"
#include "Module/VMP/VMProtectSDK.h"


int WinWidth = 645;
int WinHeight = 327;


static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};


bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();


int WINAPI WinMain(HINSTANCE, HINSTANCE, PSTR, int)
{
    //VMProtectBeginMutation("Entry point");

    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

    WNDCLASSEXW WCLASS = { sizeof(WNDCLASSEXW), CS_CLASSDC, WndProc, 64, 64, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, L"SECTOR BETA", NULL };
    RegisterClassExW(&WCLASS);

    int x = GetSystemMetrics(SM_CXSCREEN) / 2 - WinWidth / 2;
    int y = GetSystemMetrics(SM_CYSCREEN) / 2 - WinHeight / 2;

    HWND HWND = CreateWindowExW(WS_EX_NOINHERITLAYOUT, WCLASS.lpszClassName, (LPCWSTR)"SECTOR BETA", WS_POPUP, x, y, WinWidth, WinHeight, NULL, NULL, WCLASS.hInstance, NULL);

    SetLayeredWindowAttributes(HWND, RGB(0, 0, 0), 0, LWA_COLORKEY);

    if (!CreateDeviceD3D(HWND))
    {
        CleanupDeviceD3D();
        UnregisterClassW(WCLASS.lpszClassName, WCLASS.hInstance);

        return 0;
    }

    GameAddres::GetGameAddres("csgo.exe", "Counter-Strike: Global Offensive - Direct3D 9");

    Dumper::Signatures();
    Dumper::NetVars();

    GameAddresSDK::StartScan();

    ShowWindow(HWND, SW_SHOWDEFAULT);
    UpdateWindow(HWND);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& IO = ImGui::GetIO(); (void)IO;

    string FontFolder = getenv("SystemDrive") + (string)"\\Windows\\Fonts\\arialbd.ttf";
    IO.Fonts->AddFontFromFileTTF(FontFolder.c_str(), 16, NULL, IO.Fonts->GetGlyphRangesCyrillic());

    ImFont* MainFont = IO.Fonts->AddFontFromFileTTF(FontFolder.c_str(), 14, NULL, IO.Fonts->GetGlyphRangesCyrillic());

    ImGui::StyleColorsClassic();

    ImGui_ImplWin32_Init(HWND);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    MSG message;
    ZeroMemory(&message, sizeof(message));

    while (message.message != WM_QUIT)
    {
        if (PeekMessage(&message, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&message);
            ::DispatchMessage(&message);
            continue;
        }

        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();

        ImGui::NewFrame();
        {
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowSize(ImVec2(WinWidth, WinHeight));

            ImGui::Begin("SECTOR BETA", &Menu::Var::WinState, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);

            if (ImGui::Button("Visual", ImVec2(155, 30)))
                Menu::Var::TabID = 1;

            ImGui::SameLine(0.f, 5.f);

            if (ImGui::Button("Legit", ImVec2(155, 30)))
                Menu::Var::TabID = 2;

            ImGui::SameLine(0.f, 5.f);

            if (ImGui::Button("Skins", ImVec2(155, 30)))
                Menu::Var::TabID = 3;

            ImGui::SameLine(0.f, 5.f);

            if (ImGui::Button("Misc", ImVec2(155, 30)))
                Menu::Var::TabID = 4;


            ImGui::SameLine(0.f, 5.f);
            ImGui::PushFont(MainFont);

            Menu::ButtonStyle::SetBlueStyle();

            if (Menu::Var::TabID == 1)
            {
                ImGui::SetCursorPos(ImVec2(5, 62));
                ImGui::BeginChild("Glow ESP [Child]", ImVec2(200, 260), true);


                // Glow ESP

                if (ImGui::Checkbox("Glow ESP", &GlowESPSetting::Status))
                {
                    if (GlowESPSetting::Status)
                    {
                        thread _GlowESP(GlowESP);
                        _GlowESP.detach();
                    }
                }

                ImGui::SameLine(0.f, 65.f);
                ImGui::ColorEdit3("", GlowESPSetting::Color, 32);

                ImGui::Checkbox("Team check", &GlowESPSetting::TeamCheck);

                ImGui::PushItemWidth(189);

                ImGui::SliderFloat("", &GlowESPSetting::Line, 0.3, 1.0);
                Menu::SetDescription("Thickness");

                ImGui::PopItemWidth();


                // Glow ESP - Distance


                ImGui::SetWindowPos(ImVec2(5, 68));

                if (ImGui::Checkbox("Glow ESP - Distance", &GlowESP_DistanceSetting::Status))
                {
                    if (GlowESP_DistanceSetting::Status)
                    {
                        thread _GlowESP_Distance(GlowESP_Distance);
                        _GlowESP_Distance.detach();
                    }
                }

                ImGui::SameLine(0.f, 2.f);
                ImGui::ColorEdit3(" ", GlowESP_DistanceSetting::Color, 32);

                ImGui::Checkbox("Team check ", &GlowESP_DistanceSetting::TeamCheck);

                ImGui::PushItemWidth(189);

                ImGui::SliderInt(" ", &GlowESP_DistanceSetting::Distance, 10, 1000);
                Menu::SetDescription("Distance");

                ImGui::SliderFloat("  ", &GlowESP_DistanceSetting::Line, 0.3, 1.0);
                Menu::SetDescription("Thickness");

                ImGui::PopItemWidth();


                // Glow ESP - HP


                ImGui::SetWindowPos(ImVec2(5, 75));

                if (ImGui::Checkbox("Glow ESP - HP", &GlowESP_HPSetting::Status))
                {
                    if (GlowESP_HPSetting::Status)
                    {
                        thread _GlowESP_HP(GlowESP_HP);
                        _GlowESP_HP.detach();
                    }
                }

                ImGui::Checkbox("Team check  ", &GlowESP_HPSetting::TeamCheck);

                ImGui::PushItemWidth(189);

                ImGui::SliderFloat("   ", &GlowESP_HPSetting::Line, 0.3, 1.0);
                Menu::SetDescription("Thickness");

                ImGui::PopItemWidth();
                ImGui::EndChild();


                // Box ESP


                ImGui::SameLine(0.f, 18.f);
                ImGui::BeginChild("Box ESP [Child]", ImVec2(200, 260), true);

                if (ImGui::Checkbox("Enable", &RenderSetting::RenderIsStarted))
                {
                    if (RenderSetting::RenderIsStarted && !Menu::Var::RenderStarted)
                    {
                        thread _Render(BoxESP);
                        _Render.detach();


                        Menu::Var::RenderStarted = true;
                    }

                    else
                        RenderSetting::RenderIsStarted = false;
                }

                ImGui::Checkbox("Box", &RenderSetting::BoxESP);
                ImGui::Checkbox("Team check   ", &RenderSetting::TeamCheck);
                ImGui::Checkbox("HP", &RenderSetting::HP);
                ImGui::Checkbox("Gun", &RenderSetting::Gun);


                ImGui::EndChild();


                ImGui::SameLine(0.f, 17.f);
                ImGui::BeginChild("Visual misc [Child]", ImVec2(200, 260), true);


                // Chams


                if (ImGui::Checkbox("Chams", &ChamsSetting::Status))
                {
                    if (ChamsSetting::Status)
                    {
                        thread _Chams(Chams);
                        _Chams.detach();
                    }

                    else
                    {
                        thread _ChamsReset(ChamsReset);
                        _ChamsReset.detach();
                    }
                }

                ImGui::SameLine(0.f, 82.f);
                ImGui::ColorEdit3("", ChamsSetting::Color, 32);

                ImGui::Checkbox("Team check    ", &ChamsSetting::TeamCheck);

                // NightMod

                ImGui::SetWindowPos(ImVec2(440, 65));

                if (ImGui::Checkbox("Night Mod", &NightModSetting::Status))
                {
                    if (NightModSetting::Status)
                    {
                        thread _NightMod(NightMod);
                        _NightMod.detach();
                    }

                    else
                    {
                        thread _NightModReset(NightModrReset);
                        _NightModReset.detach();
                    }
                }

                ImGui::PushItemWidth(189);

                ImGui::SliderFloat("    ", &NightModSetting::Value, 0.001, 1.0f);
                Menu::SetDescription("Light");

                ImGui::PopItemWidth();


                // Brightness


                ImGui::SetWindowPos(ImVec2(440, 70));

                if (ImGui::Checkbox("Brightness", &BrightnessSetting::Status))
                {
                    if (BrightnessSetting::Status)
                    {
                        thread _Brightness(Brightness);
                        _Brightness.detach();
                    }

                    else
                        BrightnessReset();
                }

                ImGui::PushItemWidth(189);

                if (ImGui::SliderFloat("     ", &BrightnessSetting::Value, 0, 1000))
                {
                    if (BrightnessSetting::Status)
                    {
                        thread _Brightness(Brightness);
                        _Brightness.detach();
                    }
                }

                Menu::SetDescription("Light");
                ImGui::PopItemWidth();


                // Fov Changer


                ImGui::SetWindowPos(ImVec2(440, 80));

                if (ImGui::Checkbox("Fov Changer", &FovChangerSetting::Status))
                {
                    if (FovChangerSetting::Status)
                    {
                        thread _FovChanger(FovChanger);
                        _FovChanger.detach();
                    }

                    else
                    {
                        thread _FovChangerReset(FovChangerReset);
                        _FovChangerReset.detach();
                    }
                }

                ImGui::PushItemWidth(189);

                if (ImGui::SliderInt("      ", &FovChangerSetting::Fov, 10, 170))
                {
                    if (FovChangerSetting::Status)
                    {
                        thread _FovChangerForSlider(SliderFovChanger);
                        _FovChangerForSlider.detach();
                    }
                }

                Menu::SetDescription("Fov");

                ImGui::PopItemWidth();
                ImGui::EndChild();
            }


            if (Menu::Var::TabID == 2)
            {
                ImGui::SetCursorPos(ImVec2(5, 62));
                ImGui::BeginChild("Aim Bot [Child]", ImVec2(200, 260), true);

                if (ImGui::Checkbox("AimBot", &AimBotSetting::Status))
                {
                    if (AimBotSetting::Status)
                    {
                        thread _AimBot(AimBot);
                        _AimBot.detach();
                    }
                }

                ImGui::Checkbox("Team check", &AimBotSetting::TeamCheck);
                ImGui::Checkbox("Only visible", &AimBotSetting::OnlyVisible);

                ImGui::PushItemWidth(189);

                if (ImGui::Combo("       ", &Menu::Var::BoneID, Menu::Var::BoneList, IM_ARRAYSIZE(Menu::Var::BoneList)))
                {
                    switch (Menu::Var::BoneID)
                    {
                        case 0: AimBotSetting::Bone = 8; AimBotSetting::Nearest = false; break;
                        case 1: AimBotSetting::Bone = 7; AimBotSetting::Nearest = false; break;
                        case 2: AimBotSetting::Bone = 6; AimBotSetting::Nearest = false; break;
                        case 3: AimBotSetting::Bone = 4; AimBotSetting::Nearest = false; break;
                        case 4: AimBotSetting::Nearest = true; break;
                    }
                }

                Menu::SetDescription("Bone");

                ImGui::Combo("", &AimBotSetting::Key, Menu::Var::MouseList, IM_ARRAYSIZE(Menu::Var::MouseList));
                Menu::SetDescription("Mouse");

                ImGui::SliderInt(" ", &AimBotSetting::FOV, 1, 360);
                Menu::SetDescription("Fov");

                ImGui::SliderInt("  ", &AimBotSetting::Smooth, 1, 60);
                Menu::SetDescription("Smooth");

                ImGui::EndChild();


                // TriggerBot


                ImGui::SameLine(0.f, 18.f);
                ImGui::BeginChild("Trigger Bot [Child]", ImVec2(200, 260), true);

                if (ImGui::Checkbox("Trigger Bot", &TriggerBotSetting::Status))
                {
                    if (TriggerBotSetting::Status)
                    {
                        thread _TriggerBot(TriggerBot);
                        _TriggerBot.detach();
                    }
                }

                ImGui::Checkbox("Team check ", &TriggerBotSetting::TeamCheck);

                ImGui::PushItemWidth(189);

                ImGui::SliderInt("   ", &TriggerBotSetting::Delay, 0, 1000);
                Menu::SetDescription("Delay (m/s)");

                ImGui::Combo(" ", &TriggerBotSetting::Key, Menu::Var::MouseList, IM_ARRAYSIZE(Menu::Var::MouseList));
                Menu::SetDescription("Mouse");

                ImGui::EndChild();
            }


            if (Menu::Var::TabID == 3)
            {
                ImGui::SetCursorPos(ImVec2(5, 62));
                ImGui::BeginChild("Skin [Child]", ImVec2(200, 260), true);

                if (ImGui::Checkbox("Skinchanger", &SkinChangerSetting::Status))
                {
                    if (SkinChangerSetting::Status)
                    {
                        thread _SkinChanger(SkinChanger);
                        _SkinChanger.detach();
                    }
                }

                Menu::SetDescription("Update - Apply + F6");

                ImGui::PushItemWidth(189);

                ImGui::Combo(" ", &SkinChangerSDK::GunList::ActiveItem, SkinChangerSDK::GunList::AllGunList, IM_ARRAYSIZE(SkinChangerSDK::GunList::AllGunList));
                Menu::ShowGunList();

                Menu::ButtonStyle::SetBlackStyle();

                if (ImGui::Button("Apply", ImVec2(190, 25)))
                    SkinChangerSDK::ApplyGunIndex();


                Menu::ButtonStyle::SetBlueStyle();
                ImGui::PopItemWidth();
                ImGui::EndChild();


                ImGui::SameLine(0.f, 18.f);
                ImGui::BeginChild("Knifechanger [Child]", ImVec2(200, 260), true);

                if (ImGui::Checkbox("Knifechanger", &KnifeChangerSetting::Status))
                {
                    if (KnifeChangerSetting::Status)
                    {
                        thread _KnifeChanger(KnifeChanger);
                        _KnifeChanger.detach();
                    }
                }

                Menu::SetDescription("Update - F6");

                ImGui::PushItemWidth(189);
                ImGui::Combo("       ", &KnifeChangerSDK::ActiveWeapon, KnifeChangerSDK::Models::Knife, IM_ARRAYSIZE(KnifeChangerSDK::Models::Knife));
                ImGui::PopItemWidth();

                ImGui::EndChild();


                ImGui::SameLine(0.f, 18.f);
                ImGui::BeginChild("SkinSetting", ImVec2(200, 260), true);

                Menu::ButtonStyle::SetBlackStyle();

                if (ImGui::Button("Load from config", ImVec2(190, 25)))
                    Config::Skinchanger::Load();


                if (ImGui::Button("Save to config", ImVec2(190, 25)))
                {
                    int Dialog = MessageBox(0, "Âû óâåðåíû, ÷òî õîòèòå ñîõðàíèòü íàñòðîéêè ?", "", MB_YESNO);

                    if (Dialog == IDYES)
                        Config::Skinchanger::Save();
                }


                if (ImGui::Button("Set to default", ImVec2(190, 25)))
                {
                    int Dialog = MessageBox(0, "Âû óâåðåíû, ÷òî õîòèòå ñáðîèòü íàñòðîéêè ?", "", MB_YESNO);

                    if (Dialog == IDYES)
                    {
                        Config::Skinchanger::SetToDefault();
                        Config::Skinchanger::Load();
                    }
                }

                Menu::ButtonStyle::SetBlueStyle();
                ImGui::EndChild();
            }


            if (Menu::Var::TabID == 4)
            {
                ImGui::SetCursorPos(ImVec2(5, 62));
                ImGui::BeginChild("Misc [Child]", ImVec2(200, 260), true);

                if (ImGui::Checkbox("Auto Pistol", &AutoPistolSetting::Status))
                {
                    if (AutoPistolSetting::Status)
                    {
                        thread _AutoPistol(AutoPistol);
                        _AutoPistol.detach();
                    }
                }


                if (ImGui::Checkbox("Bunny Hop", &BunnyHopSetting::Status))
                {
                    if (BunnyHopSetting::Status)
                    {
                        thread _BunnyHop(BunnyHop);
                        _BunnyHop.detach();
                    }
                }


                if (ImGui::Checkbox("Radar Hack", &RadarHackSetting::Status))
                {
                    if (RadarHackSetting::Status)
                    {
                        thread _RadarHack(RadarHack);
                        _RadarHack.detach();
                    }

                    else
                    {
                        thread _RadarHackReset(RadarHackReset);
                        _RadarHackReset.detach();
                    }
                }


                if (ImGui::Checkbox("No Flash", &NoFlashSetting::Status))
                {
                    if (NoFlashSetting::Status)
                    {
                        thread _NoFlash(NoFlash);
                        _NoFlash.detach();
                    }

                    else
                    {
                        thread _NoFlashReset(NoFlashReset);
                        _NoFlashReset.detach();
                    }
                }

                ImGui::PushItemWidth(189);

                ImGui::SliderInt("", &NoFlashSetting::Value, 0, 255);
                Menu::SetDescription("Max Alpha");


                ImGui::PopItemWidth();
                ImGui::EndChild();


                ImGui::SameLine(0.f, 18.f);
                ImGui::BeginChild("Convars [Child]", ImVec2(200, 260), true);

                if (ImGui::Checkbox("FPS Boost", &ConvarsSetting::BostFPS))
                {
                    if (ConvarsSetting::BostFPS)
                    {
                        Convars::BostFPS();
                    }
                }


                if (ImGui::Checkbox("SV_CHEATS 1", &ConvarsSetting::SvCheats))
                {
                    if (ConvarsSetting::SvCheats)
                    {
                        Convars::SvCheats(1);
                    }

                    else
                    {
                        Convars::SvCheats(0);
                    }
                }


                if (ImGui::Checkbox("Grenade Preview", &ConvarsSetting::GrenadePreview))
                {
                    if (ConvarsSetting::GrenadePreview)
                    {
                        Convars::GrenadePreview(1);
                    }

                    else
                    {
                        Convars::GrenadePreview(0);
                    }
                }


                if (ImGui::Checkbox("Remove Animation", &ConvarsSetting::DrawParticles))
                {
                    if (ConvarsSetting::DrawParticles)
                    {
                        Convars::DrawParticles(0);
                    }

                    else
                    {
                        Convars::DrawParticles(1);
                    }
                }

                if (ImGui::Checkbox("Force Crosshair", &ConvarsSetting::ForceCrosshair))
                {
                    if (ConvarsSetting::ForceCrosshair)
                    {
                        Convars::ForceCrosshair(3);
                    }

                    else
                    {
                        Convars::ForceCrosshair(0);
                    }
                }


                if (ImGui::Checkbox("Aspectratio", &ConvarsSetting::AspectRatio))
                {
                    if (ConvarsSetting::AspectRatio)
                    {
                        int Dialog = MessageBox(0, "Äàííàÿ ôóíêöèÿ ìîæåò âûçûâàòü âûëåò èãðû, ïðîäîëæèòü?", "", MB_YESNO);

                        if (Dialog == IDYES)
                            Convars::Aspectratio();

                        else
                            ConvarsSetting::AspectRatio = false;
                    }

                    else
                        Convars::Aspectratio();
                }

                ImGui::PushItemWidth(189);

                if (ImGui::SliderFloat("   ", &ConvarsSetting::AspectRatioValue, 0.001, 2))
                {
                    if (ConvarsSetting::AspectRatioValue)
                        Convars::Aspectratio();
                }


                Menu::SetDescription("Value");
                ImGui::PopItemWidth();
                ImGui::EndChild();


                ImGui::SameLine(0.f, 18.f);
                ImGui::BeginChild("Setting [TAB]", ImVec2(200, 260), true);

                Menu::ButtonStyle::SetBlackStyle();


                if (ImGui::Button("Load config", ImVec2(190, 25)))
                    Config::Cheat::Load();


                if (ImGui::Button("Save config", ImVec2(190, 25)))
                {
                    int Dialog = MessageBox(0, "Âû óâåðåíû, ÷òî õîòèòå ñîõðàíèòü íàñòðîéêè ?", "", MB_YESNO);

                    if (Dialog == IDYES)
                        Config::Cheat::Save();
                }

                ImGui::EndChild();
            }


            Menu::ButtonStyle::SetBlackStyle();
            ImGui::PopFont();
            ImGui::End();
        }

        ImGui::EndFrame();

        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, NULL, 1.0f, 0);


        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
            ResetDevice();

        if (!Menu::Var::WinState)
            message.message = WM_QUIT;
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(HWND);
    UnregisterClassW(WCLASS.lpszClassName, WCLASS.hInstance);

    //VMProtectEnd();
    return 0;
}


bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;

    return true;
}


void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}


void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}


POINTS m_Pos;
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_LBUTTONDOWN:
    {
        m_Pos = MAKEPOINTS(lParam);
        return 0;
    }

    case WM_MOUSEMOVE:
    {
        if (wParam == MK_LBUTTON)
        {
            POINTS p = MAKEPOINTS(lParam);
            RECT rect;
            GetWindowRect(hWnd, &rect);

            rect.left += p.x - m_Pos.x;
            rect.top += p.y - m_Pos.y;

            if (m_Pos.x >= 0 && m_Pos.x <= WinWidth - 20 && m_Pos.y >= 0 && m_Pos.y <= ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 2.0f)
                SetWindowPos(hWnd, HWND_TOPMOST, rect.left, rect.top, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER);
        }

        return 0;
    }

    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;

    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;

        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}
