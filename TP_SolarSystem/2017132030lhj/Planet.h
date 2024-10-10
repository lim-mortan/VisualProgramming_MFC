#pragma once
class Planet
{
public:
	Planet();
	Planet(CString name, int radius, int direction,int position, int life,int speed, int angle);
	~Planet();

	CString name;
	int radius;
	int direction;
	int position;
	int life;
	int speed;

	int angle;

	CString Getname();
};

