#include <iostream>
#include "CG.h"
#include "vec.h"

using namespace std;

int main(int  argc,char *argv[]){

	if(argc == 1){
		cout << "The input is: ./prog file_name.txt "<<endl;
		exit(-1);
	}
	
	CG window;
	window.Display_SetViewport(800,600);
	
	window.Init_Render();
	window.RenderFromFile(argv[1]);
	window.Display_Render();
	window.Delay(5000);

	return 0;
}

