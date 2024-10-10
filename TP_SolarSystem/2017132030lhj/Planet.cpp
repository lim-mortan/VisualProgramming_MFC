#include "stdafx.h"
#include "Planet.h"


Planet::Planet()
{
	this->life = 0;
}


Planet::~Planet()
{
}

Planet::Planet(CString name = _T("Planet"), int radius = 10, int direction = 0, int position = 0, int life = 0, int speed =0, int angle = 0) {
	this->name = name;
	this->radius = radius;
	this->direction = direction;
	this->position = position;
	this->life = life;
	this->speed = speed;
	this->angle = angle;
}

CString Planet::Getname() {
	return name;
}