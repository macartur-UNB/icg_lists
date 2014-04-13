#ifndef MESH_H_
#define MESH_H_
#include "vec.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "CG.h"
using namespace std;

class Face{
	public:
		Face(int v1,int v2,int v3, float xn,float yn,float zn);
	 	int getV1()		const;
		int getV2()		const;	
		int getV3()		const;

		float getXn()	const;
		float getYn()	const;
		float getZn()	const;
	
	private:
		int v[3];
		float n[3];
};

class Mesh{
	public:
		Mesh();
		~Mesh();
		int load(const string fileName);
		int render();
		int resize();
		int render_room();


		void insertVertex(Line t);
		void insertFace(Face face);
	
		int getNFaces()		const;
		int getNVertex()	const;
		int getNColor()		const;

	private:
		vector<Line> *list_vertex;	
		vector<Face>	*list_face;
		float XMax,XMin,YMax,YMin,ZMax,Zmin;
};






#endif
