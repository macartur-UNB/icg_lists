#include <iostream>
#include "CG.h"
#include "vec.h"
#include "Mesh.h"



#include <vector>
using namespace std;

int main(int  argc,char *argv[]){

	if(argc == 1){
		cout << "The input is: ./prog file_name.txt "<<endl;
		exit(-1);
	}
			
	CG window;
	window.Display_SetViewport(800,600);	
	window.Init_Render();

	Mesh mesh;	
	mesh.load(argv[1]);
//	mesh.resize();
	mesh.render();

	window.Display_Render();
	window.Delay(5000);



	return 0;
}

