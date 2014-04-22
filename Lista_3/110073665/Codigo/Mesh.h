#ifndef MESH_H_
#define MESH_H_

#include "vec.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "CG.h"

using namespace std;

class Mesh{
	public:
		Mesh();
		~Mesh();
		int load(const string fileName);
		int render(string format);
		int resize();
		int translate();
		int normalize();
		void drawLine(Dot d1,Dot d2);
		void drawTriangle(Dot d1,Dot d2,Dot d3);
		void drawQuad(Dot d1,Dot d2,Dot d3,Dot d4);
		double findDeltaX();
		double findDeltaY();
		double findDeltaZ();

	private:
		vector<Dot> dot_list;	
		vector<Face>	face_list;
  	int nDots,nFaces,has_texture,has_color;
		float Xmax,Xmin,Ymax,Ymin,Zmax,Zmin,deltaX,deltaY,deltaZ;
};

#endif
