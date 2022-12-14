#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <cmath>
#include <fstream>
#include <thread>
#include <string>
#include <cstddef>
#include <mutex>
#include <intrin.h>
#include <cmath>
#include <stdio.h>
#include <Json.hpp>

#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")

#include <winsock.h>
#pragma comment(lib, "WS2_32.lib")

using namespace std;
using namespace nlohmann;

#include "GetGameAddres.h"
#include "Memory.h"
#include "Struct.h"
#include "Address.h"
#include "Var.h"
#include "Render/RenderModule.h"

#include "../Utill/ToolSDK.h"
#include "../Utill/AddresVar.h"
#include "../Utill//SDK.h"

#include "../Utill/EntityClassID.h"

#include "Dumper/Dumper.h"

#include "../Utill/GlowESP.h"
#include "../Utill/GlowESPDistance.h"
#include "../Utill/GlowESPHP.h"
#include "../Utill/AimBot.h"
#include "../Utill/AutoPistol.h"
#include "../Utill/Brightness.h"
#include "../Utill/BunnyHop.h"
#include "../Utill/Chams.h"
#include "../Utill/FakeLag.h"
#include "../Utill/FovChanger.h"
#include "../Utill/NightMod.h"
#include "../Utill/NoFlash.h"
#include "../Utill/RadarHack.h"
#include "../Utill/BoxESP.h"
#include "../Utill/SkinChangerSDK.h"
#include "../Utill/SkinChanger.h"
#include "../Utill/KnifeChangerSDK.h"
#include "../Utill/KnifeChanger.h"
#include "../Utill/TriggerBot.h"
#include "../Utill/ConvarsSDK.h"
#include "../Utill/Convars.h"

#include "../Utill/Address.h"

#include "../Menu/ImGui/imgui.h"
#include "../Menu/ImGui/imgui_impl_dx9.h"
#include "../Menu/ImGui/imgui_impl_win32.h"
#include "../Menu/MenuConfig.h"

#include "Config/Config.h"