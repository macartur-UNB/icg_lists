#ifndef DOT_H
#define DOT_H

class Dot{
	public:
		Dot(float x=0 , float y=0 , float z=0){
			this->x = x;
			this->y = y;
			this->z = z;
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
	private:
		float x,y,z;
};

class Line{
	public:
	Line(Dot d1=0,Dot d2=0,float red=0,float green=0,float blue=0){
		this->d1 = d1;
		this->d2 = d2;	
		setColor(red,green,blue);
	}
	
	Dot getDot1(){
		return this->d1;
	}
	Dot getDot2(){
		return this->d2;
	}

	void setColor(float red=0,float green=0, float blue=0){
		this->red = red;
		this->green = green;
		this->blue = blue;
	}

	float getRed(){
		return this->red;
	}
	float getGreen(){
		return this->green;
	}

	float getBlue(){
		return this->blue;
	}

	private:
		Dot d1,d2;
		float red,green,blue;
};

class Triangle{
	public:
	Triangle(Dot d1=0,Dot d2=0,Dot d3=0,float red=0,float green=0,float blue=0){
		this->d1 = d1;
		this->d2 = d2;
		this->d3 = d3;
		this->setColor(red,green,blue);
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

	void setColor(float red=0,float green=0, float blue=0){
		this->red = red;
		this->green = green;
		this->blue = blue;
	}

	float getRed(){
		return this->red;
	}
	float getGreen(){
		return this->green;
	}

	float getBlue(){
		return this->blue;
	}

	private:
		Dot d1,d2,d3;
		float red,green,blue;
};

class Quad{
	public:
	Quad(Dot d1=0,Dot d2=0, Dot d3=0, Dot d4=0,float red=0,float green=0,float blue=0){
		this->d1 = d1;
		this->d2 = d2;
		this->d3 = d3;
		this->d4 = d4;	
		this->setColor(red,green,blue);	
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


	void setColor(float red=0,float green=0, float blue=0){
		this->red = red;
		this->green = green;
		this->blue = blue;
	}

	float getRed(){
		return this->red;
	}

	float getGreen(){
		return this->green;
	}

	float getBlue(){
		return this->blue;
	}

	private:
		Dot d1,d2,d3,d4;
		float red,green,blue;
};


#endif
