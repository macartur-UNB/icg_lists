#ifndef DOT_H
#define DOT_H
#include "CG.h"
class Dot{
	public:
		Dot(float x=0 , float y=0 , float z=0,float red=1,float green=1,float blue=1,float alpha=0){
			this->x = x;
			this->y = y;
			this->z = z;
			this->r = red;
			this->g	= blue;
			this->b	= green;
			this->a = alpha;
		}
	

		 void resize(){
   		float modulo = sqrt(pow(this->getX(),2) + pow(this->getY(),2) + pow(this->getZ(),2));                    
			this->setX(this->getX()/modulo);
			this->setY(this->getY()/modulo);
			this->setZ(this->getZ()/modulo);
		}

		void setX(float x){
			this->x= x;
		}
		
		void setY(float y){
			this->z= y;
		}

		void setZ(float z){
			this->z= z;
		}

		float getX(){
			return this->x;
		}
		float getY(){
			return this->y;
		}
		float getZ(){
			return this->z;
		}

		float getRed(){
			return this->r;
		}
		float getGreen(){
			return this->g;
		}
		float getBlue(){
			return this->b;
		}

		float getAlpha(){
			return this->a;
		}

	private:
		float x,y,z,r,g,b,a;
};

class Line{
	public:
	Line(Dot d1=0,Dot d2=0){
		this->d1 = d1;
		this->d2 = d2;	
	}
	
	Dot& getDot1(){
		return this->d1;
	}
	Dot& getDot2(){
		return this->d2;
	}

	void setDot1(Dot d1){
		this->d1 = d1;
	}
	void setDot2(Dot d2){
		this->d2 = d2;
	}


	void
	DrawLine(){
	 	glBegin(GL_LINES);
			glColor4d(this->d1.getRed(),this->d1.getGreen(),this->d1.getBlue(),this->d1.getAlpha());
 		  glVertex3f(this->d1.getX(),this->d1.getY(),this->d1.getZ() );
			glColor4d(this->d2.getRed(),this->d2.getGreen(),this->d2.getBlue(),this->d2.getAlpha());	  
			glVertex3f(this->d2.getX(),this->d2.getY(),this->d2.getZ());
	 	glEnd();			
	}
	private:
		Dot d1,d2;
};

class Triangle{
	public:
	Triangle(Dot d1=0,Dot d2=0,Dot d3=0){
		this->d1 = d1;
		this->d2 = d2;
		this->d3 = d3;
	}
	
	Dot getDot1(){
		return this->d1;
	}

	Dot getDot2(){
		return this->d2;
	}
	Dot getDot3(){
		return this->d3;
	}

	void DrawTriangle(){
	 	glBegin(GL_TRIANGLES);
			glColor3d(this->d1.getRed(),this->d1.getGreen(),this->d1.getBlue());	  
 		  glVertex3f(this->d1.getX(),this->d1.getY(),this->d1.getZ() );
			glColor3d(this->d2.getRed(),this->d2.getGreen(),this->d2.getBlue());	  
			glVertex3f(this->d2.getX(),this->d2.getY(),this->d2.getZ());
			glColor3d(this->d3.getRed(),this->d3.getGreen(),this->d3.getBlue());	  
			glVertex3f(this->d3.getX(),this->d3.getY(),this->d3.getZ());
		glEnd();			
		
	}
	private:
		Dot d1,d2,d3;
};

class Quad{
	public:
	Quad(Dot d1=0,Dot d2=0, Dot d3=0, Dot d4=0){
		this->d1 = d1;
		this->d2 = d2;
		this->d3 = d3;
		this->d4 = d4;	
	}
	

	Dot getDot1(){
		return this->d1;
	}

	Dot getDot2(){
		return this->d2;
	}
	Dot getDot3(){
		return this->d3;
	}
	Dot getDot4(){
		return this->d4;	
	}
	private:
		Dot d1,d2,d3,d4;
};


#endif
