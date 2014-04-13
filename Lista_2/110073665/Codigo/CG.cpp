#include "CG.h"
#include <sstream>
#include <iostream>
#include <fstream>

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

    GLfloat ratio;

    if ( height == 0 ) {
        height = 1;
    }

    ratio = ( GLfloat )width / ( GLfloat )height;

    glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

    glMatrixMode( GL_MODELVIEW );

    glLoadIdentity( );

    return 1;
}

void
CG::DrawLine(Line line){
		Dot d1,d2;
		d1 = line.getDot1();
		d2 = line.getDot2();
	
	 	glBegin(GL_LINES);
			glColor3d(line.getRed(),line.getGreen(),line.getBlue());
 		  glVertex3f(d1.getX(),d1.getY(),d1.getZ() );
			glColor3d(line.getRed(),line.getGreen(),line.getBlue());	  
			glVertex3f(d2.getX(),d2.getY(),d2.getZ());
	 	glEnd();			
}

void
CG::DrawTriangle(Triangle triangle){
		Dot d1,d2,d3;
		d1 = triangle.getDot1();
		d2 = triangle.getDot2();
		d3 = triangle.getDot3();

	 	glBegin(GL_TRIANGLES);
			glColor3d(triangle.getRed(),triangle.getGreen(),triangle.getBlue());	  
 		  glVertex3f(d1.getX(),d1.getY(),d1.getZ() );
			glColor3d(triangle.getRed(),triangle.getGreen(),triangle.getBlue());	  
			glVertex3f(d2.getX(),d2.getY(),d2.getZ());
			glColor3d(triangle.getRed(),triangle.getGreen(),triangle.getBlue());	  
			glVertex3f(d3.getX(),d3.getY(),d3.getZ());
		glEnd();			
						
}
void
CG::DrawQuad(Quad quad){
		Dot d1,d2,d3,d4;
		d1 = quad.getDot1();
		d2 = quad.getDot2();
		d3 = quad.getDot3();
		d4 = quad.getDot4();

	 	glBegin(GL_QUADS);
			glColor3d(quad.getRed(),quad.getGreen(),quad.getBlue());
 		  glVertex3f(d1.getX(),d1.getY(),d1.getZ() );
			glColor3d(quad.getRed(),quad.getGreen(),quad.getBlue());	  
			glVertex3f(d2.getX(),d2.getY(),d2.getZ());
			glColor3d(quad.getRed(),quad.getGreen(),quad.getBlue());
			glVertex3f(d3.getX(),d3.getY(),d3.getZ());
			glColor3d(quad.getRed(),quad.getGreen(),quad.getBlue());
			glVertex3f(d4.getX(),d4.getY(),d4.getZ());
	 	glEnd();			
}

void 
CG::Init_Render(){
		glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
    glTranslatef( -1.5f, 0.0f, -6.0f );
}

void 
CG::Display_Render()
{
  	SDL_GL_SwapWindow(this->displayWindow);
}


void
CG::RenderFromFile(string file_name){
	string line;
	float x,y,z;
	int n,m,o,p,k,l,j;
	int idots=0,ivertex=0,itriangle=0;
	char buffer;
	Dot * dot = new Dot[5];
	Line * vertex = new Line[8];	
	Triangle * triangle = new Triangle[4];
	
	ifstream input (file_name.c_str());

	if(input.is_open()){

		while(getline(input,line)){
			istringstream iss(line);
			if(line[0] == 'd'){
				iss >> buffer  >>  x >> y  >> z;
				dot[idots] = Dot(x,y,z);
				idots++;		
			}else if(line[0]== 'l'){
				iss >>buffer >>n >> m  >> k >> l >> j;
				vertex[ivertex] = Line(dot[n-1],dot[m-1],k,l,j);  
				this->DrawLine(vertex[ivertex]);
				ivertex++;
			}else if(line[0] == 't'){
				iss >> buffer >>n >> m >> o >> k >> l >> j;	
				triangle[itriangle] = Triangle(dot[n-1],dot[m-1],dot[o-1],k,l,j);	
				this->DrawTriangle(triangle[itriangle]);
				itriangle++;
			}else if(line[0] == 'q'){
    		iss>> buffer >>n >> m >> o >> p >> k >>l >>j;
				Quad quad = Quad(dot[n-1],dot[m-1],dot[o-1],dot[p-1],k,l,j); 
				this->DrawQuad(quad);
			}
		
		}
		input.close();
	}else{
		cout << "Unable to open file"<<endl;
	}	
}




