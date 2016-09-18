#ifndef Weather_H
#define Weather_H


#include<GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

class Weather
{
private: 
	//Movement Variables
	float Pos[3];
	float Dir[3];
	float speed;

	//Attribute Variables
	float colourVec[4];//an array that stores 3 colour values and a transparency value
	int age;//how long the particle has been alive for, particicles dissapear after a while

public:
	enum Type {Rain, Snow, Clear}type;//Precipitation has types 

	//constructor
	Weather(float* pos, float* dir, Type inType);

	void move(float floorSize);
	void draw();

	int getAge();
};

#endif
