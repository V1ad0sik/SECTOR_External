#pragma once

#include <dinput.h>
#include <dwmapi.h>
#include <string>
#include <thread>
#include <windows.h>
#include <stdexcept>

using namespace std;

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "dwmapi.lib")
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

#include "dxRenderer/dx_renderer.h"
#include "dxOverlay/dx_overlay.h"