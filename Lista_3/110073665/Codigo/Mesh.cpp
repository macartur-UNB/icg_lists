#include "Mesh.h"
#include <GL/gl.h>
#include <GL/glu.h>

Mesh::Mesh(){}

Mesh::~Mesh(){}

int
Mesh::load(const string fileName) 
{

	if( fileName.substr(fileName.size()-4,fileName.size()-1)== ".off")
	{
		cout << "File is supported" << endl;
	
	}else{
		cout << "File is not supported" <<endl;
		exit(-1);
	}
		

  ifstream file(fileName.c_str());

	if(!file.is_open())
	{	
			cout << "Can't open the file" << endl;
			exit(-1);
	}

	string buffer1;
	getline(file,buffer1);
	if(buffer1 == "COFF")
	{
		this->has_color = 1;
		cout << "Color: true"<<endl;
	}else{
		this->has_color = 0;
		cout << "Color: false"<<endl;
	}
	string line;
	getline(file,line);
	stringstream ss(line);

	ss >> this->nDots >> this->nFaces >> this->has_texture;

	if(this->has_texture)
		cout << "Texture: true"<<endl;
	else
		cout << "Texture: false"<<endl;
	
	
	for( int i=0;i<this->nDots;i++)
	{
		float x,y,z;
		int r,g,b,a;
		x=y=z=0;
		g=b=r=1;
		a=0;

		string linha;
		getline(file,linha);
		stringstream buffer(linha);

		if(this->has_color != 0){
			buffer >> x >> y >> z >> r >> g >> b >> a ;
		}else{
			buffer >> x >> y >> z ;
		}

		Dot dot(x,y,z,r,g,b,a);	 
		dot_list.push_back(dot);
	}

	for( int i=0;i<this->nFaces;i++)
	{
		string linha;
		getline(file,linha);
		stringstream ss(linha);
		
		int tipo,index0,index1,index2,index3;
		ss >> tipo>> index0 >> index1 >> index2 >> index3;
			
		if(tipo == 4)
		{
	  	face_list.push_back(Face(index0,index1,index2,index3));
		}else if(tipo == 3){
	  	face_list.push_back(Face(index0,index1,index2));
		}else{
			cout << "has type = "<< tipo << "in the file."<< endl;			
			exit(-1);
		}
		
	}
	file.close();

	cout << "Dots: "<<this->nDots<<"/"<< this->dot_list.size()<<endl;
	cout << "Faces: "<<this->nFaces << "/"<<this->face_list.size()<<endl;

	this->deltaX = this->findDeltaX();
	this->deltaY = this->findDeltaY();
	this->deltaZ = this->findDeltaZ();

	return 0;
}

int
Mesh::render(string format) {

	if(format == "line"){
		for(unsigned int i=0;i<this->face_list.size();i++)
		{
			int index0,index1,index2,index3;

			index0 = this->face_list[i].getI0();
			index1 = this->face_list[i].getI1();
			index2 = this->face_list[i].getI2();
			index3 = this->face_list[i].getI3();

			if(index3 == -1){
				drawLine(this->dot_list[index0],this->dot_list[index1]);
				drawLine(this->dot_list[index1],this->dot_list[index2]);
				drawLine(this->dot_list[index2],this->dot_list[index1]);
			}else{
				drawLine(this->dot_list[index0],this->dot_list[index1]);
				drawLine(this->dot_list[index1],this->dot_list[index2]);
				drawLine(this->dot_list[index2],this->dot_list[index3]);
				drawLine(this->dot_list[index3],this->dot_list[index0]);
			}
		}
	}else if(format == "polygon"){
		for(unsigned int i=0;i<this->face_list.size();i++)
		{
			int index0,index1,index2,index3;

			index0 = this->face_list[i].getI0();
			index1 = this->face_list[i].getI1();
			index2 = this->face_list[i].getI2();
			index3 = this->face_list[i].getI3();

			if(index3 == -1){
				drawTriangle(this->dot_list[index0],this->dot_list[index1],this->dot_list[index2]);
			}else{
				drawQuad(this->dot_list[index0],this->dot_list[index1],this->dot_list[index2],this->dot_list[index3]);
			}
		}
	}else{
		cout << "Format parameter invalid. <format> = line or polygon"<< endl;
		exit(-1);
	}

 	return 0;
}

void 
Mesh::drawLine(Dot d1,Dot d2){
		glBegin(GL_LINES);
			glColor4d(d1.getRed(),d1.getGreen(),d1.getBlue(),d1.getAlpha() );
			glVertex3f(d1.getX(),d1.getY(),d1.getZ());
			glColor4d(d2.getRed(),d2.getGreen(),d2.getBlue(),d2.getAlpha() );
			glVertex3f(d2.getX(),d2.getY(),d2.getZ());
		glEnd();
}

void 
Mesh::drawTriangle(Dot d1,Dot d2,Dot d3){
		glBegin(GL_TRIANGLES);
			glColor4d(d1.getRed(),d1.getGreen(),d1.getBlue(),d1.getAlpha() );
			glVertex3f(d1.getX(),d1.getY(),d1.getZ());
			glColor4d(d2.getRed(),d2.getGreen(),d2.getBlue(),d2.getAlpha() );
			glVertex3f(d2.getX(),d2.getY(),d2.getZ());
			glColor4d(d3.getRed(),d3.getGreen(),d3.getBlue(),d3.getAlpha() );
			glVertex3f(d3.getX(),d3.getY(),d3.getZ());
		glEnd();
}

void 
Mesh::drawQuad(Dot d1,Dot d2,Dot d3,Dot d4){
		glBegin(GL_QUADS);
			glColor4d(d1.getRed(),d1.getGreen(),d1.getBlue(),d1.getAlpha() );
			glVertex3f(d1.getX(),d1.getY(),d1.getZ());
			glColor4d(d2.getRed(),d2.getGreen(),d2.getBlue(),d2.getAlpha() );
			glVertex3f(d2.getX(),d2.getY(),d2.getZ());
			glColor4d(d3.getRed(),d3.getGreen(),d3.getBlue(),d3.getAlpha() );
			glVertex3f(d3.getX(),d3.getY(),d3.getZ());
			glColor4d(d4.getRed(),d4.getGreen(),d4.getBlue(),d4.getAlpha() );
			glVertex3f(d4.getX(),d4.getY(),d4.getZ());
		glEnd();
}

int 
Mesh::resize() {
	
	for(unsigned int i=0;i<this->dot_list.size();i++)
	{
		this->dot_list[i].setX(dot_list[i].getX()/this->deltaX);
		this->dot_list[i].setY(dot_list[i].getY()/this->deltaY);
		this->dot_list[i].setZ(dot_list[i].getZ()/this->deltaZ);
	}

	this->deltaX = this->findDeltaX();
	this->deltaY = this->findDeltaY();
	this->deltaZ = this->findDeltaZ();

 	return 0; 
}

int 
Mesh::translate()
{
	
	for(unsigned int i=0;i<this->dot_list.size();i++)
	{
		this->dot_list[i].setX(dot_list[i].getX() - (this->deltaX/2) + this->Xmin);
		this->dot_list[i].setY(dot_list[i].getY() - (this->deltaY/2) + this->Ymin);
		this->dot_list[i].setZ(dot_list[i].getZ() - (this->deltaZ/2) + this->Zmin);
	}
	return 0;
}

int 
Mesh::normalize()
{
	return 0;
}

double
Mesh::findDeltaX()
{
		double Xmax = dot_list[0].getX();
    double Xmin = dot_list[0].getX();
 
    for(unsigned int i=1; i<this->dot_list.size(); i++)
    {
      if(dot_list[i].getX() > Xmax)
        Xmax = dot_list[i].getX();
  
      if(dot_list[i].getX() < Xmin)
        Xmin = dot_list[i].getX();
    }
  
    this->Xmin = Xmin;
  
    return Xmax - Xmin;
}
double
Mesh::findDeltaY()
{

		double Ymax = dot_list[0].getY();
    double Ymin = dot_list[0].getY();
 
    for(unsigned int i=1; i<this->dot_list.size(); i++)
    {
      if(dot_list[i].getX() > Ymax)
        Ymax = dot_list[i].getX();
  
      if(dot_list[i].getX() < Ymin)
        Ymin = dot_list[i].getX();
    }
  
    this->Ymin = Ymin;
  
    return Ymax - Ymin;

}
double 
Mesh::findDeltaZ()
{

		double Zmax = dot_list[0].getZ();
    double Zmin = dot_list[0].getZ();
 
    for(unsigned int i=1; i<this->dot_list.size(); i++)
    {
      if(dot_list[i].getX() > Zmax)
        Zmax = dot_list[i].getZ();
  
      if(dot_list[i].getZ() < Zmin)
        Zmin = dot_list[i].getZ();
    }
  
    this->Zmin = Zmin;
  
    return Zmax - Zmin;
}
