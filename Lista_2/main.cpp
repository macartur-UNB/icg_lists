#include <iostream>
#include "CG.h"
#include "vec.h"

using namespace std;

int main(){
	
	//cria uma estrutura usando o CG , para criar a janela e o viewport
	CG window;
	window.Display_SetViewport(800,600);
	
	window.Init_Render();

//	window.RenderFromFile("line_input.txt");
		window.RenderFromFile("triangle_and_quad_input.txt");

	window.Display_Render();
	window.Delay(2000);

	return 0;
}

