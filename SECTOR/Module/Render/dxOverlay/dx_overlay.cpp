#pragma once


#include "../RenderModule.h"


namespace forceinline
{
	dx_overlay::dx_overlay(wstring_view target_class, wstring_view target_window, bool not_topmost)
	{
		m_not_topmost = not_topmost;


		if (target_window.empty() && target_class.empty())
			throw invalid_argument("dx_overlay::dx_overlay: target_class and target_window empty");


		if (m_target_wnd = FindWindowW(target_class.empty() ? NULL: target_class.data(), target_window.empty() ? NULL: target_window.data()); !m_target_wnd)
		{
			string target_class_mb( target_class.begin( ), target_class.end( ) );
			string target_window_mb( target_window.begin( ), target_window.end( ) );

			throw invalid_argument("dx_overlay::dx_overlay: target window \"" + target_window_mb + "\" with target class \"" + target_class_mb + "\" could not be found");
		}

		create_overlay(target_class, target_window);
	}


	dx_overlay::~dx_overlay()
	{
		if (m_overlay_wnd)
			DestroyWindow(m_overlay_wnd);

		if (m_d3d)
			m_d3d->Release();

		if (m_device)
			m_device->Release();
	}
	

	dx_renderer dx_overlay::create_renderer()
	{
		return dx_renderer( m_device );	
	}

	HWND dx_overlay::get_overlay_wnd()
	{
		return m_overlay_wnd;
	}

	void dx_overlay::create_overlay(wstring_view target_class, wstring_view target_window)
	{
		WNDCLASSEX wc;
		wc.cbSize = sizeof( wc );

		wc.style = CS_HREDRAW | CS_VREDRAW | WS_EX_TOOLWINDOW;
		wc.lpfnWndProc = m_wnd_proc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = NULL;
		wc.hIcon = NULL;
		wc.hCursor = LoadCursor( NULL, IDC_ARROW );
		wc.hbrBackground = HBRUSH( RGB( 0, 0, 0 ) );
		wc.lpszMenuName = "";
		wc.lpszClassName = "forceinline::dx_overlay";
		wc.hIconSm = NULL;


		if (!RegisterClassExA(&wc))
			throw exception("dx_overlay::create_overlay: failed to register wndclassex");


		GetWindowRect(m_target_wnd, &m_target_wnd_size);

		DWORD ex_styles = WS_EX_LAYERED | WS_EX_TRANSPARENT;

		if (!m_not_topmost)
			ex_styles |= WS_EX_TOPMOST;

		m_overlay_wnd = CreateWindowExA(ex_styles, "forceinline::dx_overlay", "", WS_POPUP | WS_VISIBLE, m_target_wnd_size.left, m_target_wnd_size.top, m_target_wnd_size.width(), m_target_wnd_size.height(), NULL, NULL, NULL, NULL);

		if (!m_overlay_wnd)
			throw exception("dx_overlay::create_overlay: failed to create overlay window");


		MARGINS m = {m_target_wnd_size.left, m_target_wnd_size.top, m_target_wnd_size.width(), m_target_wnd_size.height()};
		DwmExtendFrameIntoClientArea( m_overlay_wnd, &m );

		SetLayeredWindowAttributes(m_overlay_wnd, RGB(0, 0, 0), 255, LWA_ALPHA);

		ShowWindow(m_overlay_wnd, SW_SHOW);
		init_dx9();
	}


	void dx_overlay::init_dx9( )
	{
		m_d3d = Direct3DCreate9(D3D_SDK_VERSION);

		if (!m_d3d)
			throw exception("dx_overlay::init_dx9: failed to create dx3d9 object");


		D3DPRESENT_PARAMETERS d3d_pp;
		ZeroMemory( &d3d_pp, sizeof(d3d_pp));


		d3d_pp.Windowed = true;
		d3d_pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3d_pp.BackBufferFormat = D3DFMT_A8R8G8B8;
		d3d_pp.BackBufferWidth = m_target_wnd_size.width( );
		d3d_pp.BackBufferHeight = m_target_wnd_size.height( );
		d3d_pp.hDeviceWindow = m_overlay_wnd;
		d3d_pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	
		if (FAILED( m_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_overlay_wnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3d_pp, &m_device)))
		{
			m_d3d->Release();
			throw exception("dx_overlay::init_dx9: failed to create device");
		}
	}


	bool dx_overlay::m_not_topmost = false;
	HWND dx_overlay::m_target_wnd, dx_overlay::m_overlay_wnd;

	LRESULT CALLBACK dx_overlay::m_wnd_proc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		if (m_not_topmost)
		{
			wnd_rect_t r;

			GetWindowRect(m_target_wnd, &r);
			SetWindowPos(m_target_wnd, m_overlay_wnd, r.left, r.top, r.width(), r.height(), SWP_NOMOVE | SWP_NOSIZE);
		}

		return DefWindowProc(wnd, msg, wparam, lparam);
	}
}