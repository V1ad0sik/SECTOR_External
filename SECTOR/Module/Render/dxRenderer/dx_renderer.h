#pragma once


#include "../RenderModule.h"


namespace forceinline
{
	class dx_renderer
	{

	private: 

		struct D3DTLVERTEX
		{
			float x, y, z, rhw;
			unsigned long color;
		};


	public:
		dx_renderer() {}
		dx_renderer(IDirect3DDevice9* device);
		~dx_renderer();

		void begin_rendering();
		void end_rendering();


		void draw_line(int x0, int y0, int x1, int y1, unsigned long color);
		void draw_solid_line(int x, int y, int w, int h, unsigned long color);
		void draw_rect(int x, int y, int w, int h, unsigned long color);
		void draw_filled_rect(int x, int y, int w, int h, unsigned long color);
		void draw_outlined_rect(int x, int y, int w, int h, unsigned long color);
		void draw_text(wstring_view text, int x, int y, unsigned long color, bool center = true, bool outline = true);

		RECT get_text_dimensions(wstring_view text);


	private:
		IDirect3DDevice9* m_device = nullptr;

		ID3DXFont* m_font = nullptr;
		ID3DXLine* m_line = nullptr;
	};

}