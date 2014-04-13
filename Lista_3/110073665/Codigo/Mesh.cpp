#include "Mesh.h"

Face::Face(int v1=0,int v2=0,int v3=0,float xn=0,float yn=0,float zn=0)
{
	this->v[0] = v1;
	this->v[1] = v2;
	this->v[2] = v3;
	
	this->n[0] = xn;
	this->n[1] = yn;
	this->n[2] = zn;
}
int
Face::getV1()	const
{
	return this->v[0];
}
int
Face::getV2()	const
{
	return this->v[1];
}
int
Face::getV3()	const
{
	return this->v[2];
}

float
Face::getXn()	const
{
	return this->n[0];
}
float
Face::getYn()	const
{
	return this->n[1];
}

float
Face::getZn()	const
{
	return this->n[2];
}

Mesh::Mesh(){
	this->list_vertex = new vector<Line>();
	this->list_face = new vector<Face>();
}

Mesh::~Mesh(){}

int
Mesh::load(const string fileName) 
{
	string buffer;
	int dots;
	int vertex;
	vector<Dot> list_of_dots;
	float x,y,z,r,g,b,has_color,has_texture;
	int alpha;
	x=y=z=0;
	r=g=b=1;

	ifstream input (fileName.c_str());

	//verifica se é arquivo.off
	if( fileName.substr(fileName.size()-5,4) != ".off"){
		cout << "Arquivo correto"<<endl;
	}else{
		cout << "Arquivo incorreto"<<endl;
		return -1;
	}


	if(input.is_open()){
		//ler COFF ou OFF
		input >> buffer ;

		if(buffer=="COFF")
			has_color=1;
		else
			has_color=0;
	
		//ler numero de pontos
		input >> dots;
		//ler numero de vertex
		input >> vertex;
		//textura
		input >> has_texture;

		if(has_texture)
			cout <<"A imagem tem textura" << endl;


		//faz a leitura de todos os pontos
		for(int i=0;i<=dots;i++)
		{
			if(has_color == 1)
			{
				input >> x >> y >> z >> r >> g >> b >>alpha ;
			}else{
				input >> x >> y >> z >> alpha;		
			}
			list_of_dots.push_back(Dot(x,y,z,r,g,b,alpha));
		}

		//faz leitura de todos os vertex
		for(int i=0;i<=vertex;i++)
		{
			//PODE ACONTECER UM ERRO AQUI 
			//buffer esta lendo o 3 , que quer dizer um triangulo
			input >>buffer >>	x >> y >> z;

			Line l1(list_of_dots[x],list_of_dots[y]);
			Line l2(list_of_dots[y],list_of_dots[z]);
			Line l3(list_of_dots[z],list_of_dots[x]);

			this->insertVertex(l1);
			this->insertVertex(l2);
			this->insertVertex(l3);
		}
		input.close();
	}else{
		cout << "Unable open the file"<< fileName<<endl;
	}
	return 0;
}

int
Mesh::render()
{
	for(unsigned int i=0;i<this->list_vertex->size();i++)
	{
		Line l1 = this->list_vertex->at(i);
		l1.DrawLine();
	}
	cout << "fim render"<<endl;
	return 0;
}
int 
Mesh::resize()
{
	for(unsigned int i=0;i<this->list_vertex->size();i++){
			this->list_vertex->at(i).getDot1().resize();
			this->list_vertex->at(i).getDot2().resize();
	}

	return 0;
}
int
Mesh::render_room()
{
	return 0;
}

int
Mesh::getNFaces()	const
{
	return this->list_face->size();
}
int
Mesh::getNVertex()	const
{
	return this->list_vertex->size();
}

void 
Mesh::insertVertex(Line t)
{
	this->list_vertex->push_back(t);
}
void
Mesh::insertFace(Face face)
{
	this->list_face->push_back(face);
}

