#ifndef CG_H
#define CG_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class CG{
	public:
		CG(int width=800,int height=600);
		~CG();
		
		void Display_InitGL();		
		int  Display_SetViewport( int width, int height );
		void Delay(int time);
		void Init_Render();
		void Display_Render();

	private:
		SDL_Window* displayWindow;
		SDL_Renderer* displayRenderer;
		int flags;
};

#endif
