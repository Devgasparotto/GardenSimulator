#include "Weather.h"

//Weather constructor
Weather::Weather(float* pos, float* dir, Type inType)
{
	Pos[0] = pos[0];
	Pos[1] = pos[1];
	Pos[2] = pos[2];

	Dir[0] = dir[0];
	Dir[1] = dir[1];
	Dir[2] = dir[2];


	type = inType;

	//Determine what colour the precipitation is
	switch(type)
	{
		case Snow:
			colourVec[0] = 1;//Snow is White
			colourVec[1] = 1;
			colourVec[2] = 1;
			colourVec[3] = 1;//Snow is not transparent
			break;
		
		case Rain:
			colourVec[0] = 0;//Rain is Blue
			colourVec[1] = 0.5;
			colourVec[2] = 1;
			colourVec[3] = 0.9;//Rain is slightly transparent
			break;
	}

	age = 0;
	speed = 1;
}

void Weather::move(float floorSize)
{
	//***** Ground Hit Detection *****//
	//Particle reaches the ground
	if((Pos[1] -.981/60) <= 0 && 
	  ((Pos[0] < floorSize/2 && Pos[0] > -floorSize/2) &&
		(Pos[2] < floorSize/2 && Pos[2] > -floorSize/2)))
	{
		age = 9001; //set age to a high value so the particle will be deleted
	}

	//***** Movement *****//
	Pos[0] = Pos[0] + Dir[0] *speed;
	Pos[1] = Pos[1] + Dir[1] *speed;
	Pos[2] = Pos[2] + Dir[2] *speed;

	//***** Gravity *****//
	if(type == Snow)//Snow
	{
		Dir[1] = Dir[1] + -0.001*Dir[1]/60 - 0.1/300;//Snow is light and does not fall as fast
	}
	else//Rain
	{
		Dir[1] = Dir[1] -0.981/180;//Rain falls normally due to gravity
	}

	//Particle grows in age for every move, after a certain age Particles will be deleted.
	age++;
}

void Weather::draw()
{
	glColor4fv(colourVec);
	glPushMatrix();{	
		glTranslatef(Pos[0],Pos[1],Pos[2]);

		//Drawing the Particle
		glPointSize(3);
		glBegin(GL_POINTS);
			glVertex3f(0,0,0);
		glEnd();
	}glPopMatrix();
}

int Weather::getAge(){ return age;}



