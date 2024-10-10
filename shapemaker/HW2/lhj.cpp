#include <iostream> 
#include <string> 
using namespace std;

class Shape {
private:
	int x, y, area;
public:
	virtual void Draw() {}
	void setPosition(int a, int b) {
		x = a;
		y = b;
	}
	void setArea(double a) {
		area = a;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	double getarea() {
		return area;
	}
};

class Rectangle : public Shape {
protected:
	int width, height;
public:
	Rectangle(int a, int b, int c, int d) {
		width = c;
		height = d;
		setPosition(a, b);
		setArea(rectangleArea());
	}
	double rectangleArea() {
		return width*height;
	}
	void Draw() {
		cout << "[Rectangle] Position = < " << getx() << " , " << gety() << " >" << endl;
		cout << "Size = < " << width << " , " << height << " >" << endl;
		cout << "Area = " << getarea() << "\n" << endl;
	}
};

class Triangle : public Shape {
protected:
	int base, length;
public:
	Triangle(int a, int b, int c, int d) {
		base = c;
		length = d;
		setPosition(a, b);
		setArea(triangleArea());
	}
	double triangleArea() {
		return base*length*0.5;
	}
	void Draw() {
		cout << "[Triangle] Position = < " << getx() << " , " << gety() << " >" << endl;
		cout << "Size = < " << base << " , " << length << " >" << endl;
		cout << "Area = " << getarea() << "\n" << endl;
	}
};

class Circle : public Shape {
protected:
	int radius;
public:
	Circle(int a, int b, int c) {
		radius = c;
		setPosition(a, b);
		setArea(circleArea());
	}
	double circleArea() {
		return radius*radius*3.14;
	}
	void Draw() {
		cout << "[Circle] Position = < " << getx() << " , " << gety() << " >" << endl;
		cout << "Radius = " << radius << endl;
		cout << "Area = " << getarea() << "\n" << endl;
	}
};

void main()
{
	Shape* shapes[5] = { NULL };
	shapes[0] = new Circle(100, 100, 50);
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Triangle(200, 200, 200, 200);
	for (int i = 0; i<5; ++i)
		shapes[i]->Draw();
	for (int i = 0; i<5; ++i)
	{
		delete shapes[i];
		shapes[i] = NULL;
	}
}