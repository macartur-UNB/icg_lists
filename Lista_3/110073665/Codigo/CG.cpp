#include "CG.h"

using namespace std;

CG::CG(int width,int height){

	SDL_Init(SDL_INIT_VIDEO);
  this->flags = SDL_WINDOW_OPENGL;

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_CreateWindowAndRenderer(width,height, this->flags,&this->displayWindow, &this->displayRenderer);
	SDL_GL_CreateContext(this->displayWindow);
  Display_InitGL();
}

CG::~CG(){
	SDL_Quit();
}

void 
CG::Delay(int time){
	SDL_Delay(time);
}


void 
CG::Display_InitGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
}


int 
CG::Display_SetViewport( int width, int height )
{
    if ( height == 0 )  height = 1;
		glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );
    return 1;
}

void 
CG::Init_Render(){
		glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void 
CG::Display_Render()
{
  	SDL_GL_SwapWindow(this->displayWindow);
}
