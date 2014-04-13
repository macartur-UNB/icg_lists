#ifndef CG_H
#define CG_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include <sstream>

using namespace std;

#include "vec.h"


class CG{
	public:
		CG(int width=800,int height=600);
		~CG();
		void Display_InitGL();		

		int  Display_SetViewport( int width, int height );
		void Delay(int time);

		void DrawLine(Line line);
		void DrawTriangle(Triangle triangle);
		void DrawQuad(Quad quad);

		void Init_Render();
		void Display_Render();

		void RenderFromFile(string file_name);

	private:
		SDL_Window* displayWindow;
		SDL_Renderer* displayRenderer;
		int flags;
};





#endif
