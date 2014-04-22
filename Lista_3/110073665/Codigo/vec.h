#ifndef DOT_H
#define DOT_H

#include "CG.h"

class Dot{
	public:
		Dot(float x=0.0 , float y=0.0 , float z=0.0,
				float red=1,float green=1,float blue=1,
				float alpha=0.0){
			this->x = x;
			this->y = y;
			this->z = z;
			this->r = red;
			this->g	= blue;
			this->b	= green;
			this->a = alpha;
		}
		void setX(float x){	this->x= x;}
		void setY(float y){	this->y= y;}
		void setZ(float z){	this->z= z;}

		float getX(){				return this->x;}
		float getY(){				return this->y;}
		float getZ(){				return this->z;}
		float getRed(){			return this->r;}
		float getGreen(){		return this->g;}
		float getBlue(){		return this->b;}
		float getAlpha(){		return this->a;}

	private:
		float x,y,z,r,g,b,a;
};

class Face{
	public:
		Face( int i0=0, int i1=0, int i2=0,int i3=-1){
			this->i[0] = i0;
			this->i[1] = i1;
			this->i[2] = i2;
			this->i[3] = i3;
		}

	 	int getI0()		const {		return this->i[0]; }
		int getI1()		const	{		return this->i[1]; }	
		int getI2()		const	{		return this->i[2]; }
		int getI3()		const	{		return this->i[3]; }
	private:
		int i[4];
};
#endif
