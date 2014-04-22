#include <iostream>
#include "CG.h"
#include "Mesh.h"

using namespace std;

int main(int  argc,char *argv[]){

	if(argc < 3 ){
		cout << "The input is: ./prog <file_name.off> <type>  "<<endl;
		exit(-1);
	}
			
	CG window;
	window.Display_SetViewport(800,600);	
	window.Init_Render();

	Mesh mesh;	
	mesh.load(argv[1]);
	mesh.resize();
	mesh.render(argv[2]);

	window.Display_Render();

	window.Delay(5000);

	return 0;
}

