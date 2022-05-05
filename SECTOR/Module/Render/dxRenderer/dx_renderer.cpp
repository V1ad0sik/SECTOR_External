#pragma once


#include "../RenderModule.h"


namespace forceinline
{
	dx_renderer::dx_renderer(IDirect3DDevice9* device)
	{
		if (!device)
			throw invalid_argument("dx_renderer::dx_renderer: device is nullptr");

		m_device = device;


		if (FAILED(D3DXCreateLine(m_device, &m_line)))
			throw exception("dx_renderer::dx_renderer: failed to create line");


		if (FAILED(D3DXCreateFont(m_device, 12, NULL, FW_HEAVY, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &m_font)))
			throw exception("dx_renderer::dx_renderer: failed to create font");
	}


	dx_renderer::~dx_renderer()
	{
		if (m_font)
			m_font->Release();

		if (m_line)
			m_line->Release();
	}


	void dx_renderer::begin_rendering()
	{
		m_device->Clear(NULL, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.f, 0);
		m_device->BeginScene();
	}


	void dx_renderer::end_rendering()
	{
		m_device->EndScene();
		m_device->Present(NULL, NULL, NULL, NULL);
	}


	void dx_renderer::draw_line(int x0, int y0, int x1, int y1, unsigned long color)
	{		
		D3DXVECTOR2 lines[2]
		{
			D3DXVECTOR2(x0, y0),
			D3DXVECTOR2(x1, y1)
		};

		m_line->Begin();
		m_line->Draw(lines, 2, color);
		m_line->End();
	}


	void dx_renderer::draw_rect(int x, int y, int w, int h, unsigned long color)
	{
		draw_line(x, y, x + w, y, color);
		draw_line(x, y, x, y + h, color);
		draw_line(x + w, y, x + w, y + h, color);
		draw_line(x, y + h, x + w, y + h, color);
	}


	void dx_renderer::draw_filled_rect(int x, int y, int w, int h, unsigned long color)
	{
		D3DTLVERTEX qV[4]
		{
			{float(x), float(y + h), 0.f, 1.f, color},
			{float(x), float(y), 0.f, 1.f, color},
			{float(x + w), float(y + h), 0.f, 1.f, color},
			{float(x + w), float(y) , 0.f, 1.f, color}
		};
		
		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		m_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		m_device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
		m_device->SetTexture(0, nullptr);
		m_device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, qV, sizeof(D3DTLVERTEX));
	}


	void dx_renderer::draw_outlined_rect(int x, int y, int w, int h, unsigned long color)
	{
		draw_rect(x - 1, y - 1, w + 2, h + 2, D3DCOLOR_RGBA(1, 1, 1, 255));
		draw_rect(x + 1, y + 1, w - 2, h - 2, D3DCOLOR_RGBA(1, 1, 1, 255));
		draw_rect(x, y, w, h, color);
	}


	void dx_renderer::draw_solid_line(int x, int y, int w, int h, unsigned long color)
	{
		draw_line(x + 1, y + 1, w, h, color);
		draw_line(x, y, w, h, color);
	}


	void dx_renderer::draw_text(wstring_view text, int x, int y, unsigned long color, bool center, bool outline)
	{
		if (center)
		{
			RECT dimensions = get_text_dimensions(text);
			x -= (dimensions.right - dimensions.left) / 2;
		}

		auto _text = [&](wstring_view text, int _x, int _y, unsigned long _color)
		{
			RECT r{_x, _y, _x, _y};
			m_font->DrawTextW(NULL, text.data(), -1, &r, DT_NOCLIP, _color);
		};


		if (outline)
		{
			_text(text, x - 1, y, D3DCOLOR_RGBA(1, 1, 1, 255));
			_text(text, x + 1, y, D3DCOLOR_RGBA(1, 1, 1, 255));
			_text(text, x, y - 1, D3DCOLOR_RGBA(1, 1, 1, 255));
			_text(text, x, y + 1, D3DCOLOR_RGBA(1, 1, 1, 255));
		}

		_text(text, x, y, color);
	}

	RECT dx_renderer::get_text_dimensions(wstring_view text )
	{
		RECT r;
		m_font->DrawTextW(NULL, text.data(), -1, &r, DT_CALCRECT, 0xFFFFFFFF);

		return r;
	}
}