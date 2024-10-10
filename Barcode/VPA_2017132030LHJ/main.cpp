#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date() {		//인수가 없는 기본생성자
		year = 0;
		month = 0;
		day = 0;
	}
	Date(int y, int m, int d) {		//매개변수 3개 받아서 멤버변수에 저장
		year = y;
		month = m;
		day = d;
	}
	void setYear(int y) { //년 설정자
		year = y;
	}
	void setMonth(int m) {//월 설정자
		month = m;
	}
	void setDay(int d) {//일 설정자
		day = d;
	}
	int getYear() {//년 접근자
		return year;
	}
	int getMonth() {//월 접근자
		return month;
	}
	int getDay() {//일 접근자
		return day;
	}
};

class Product : public Date {// Date 클래스 상속
private:
	string name;
	string manufacturer;
	int price;
public:
	Product() {// 인수가 없는 기본 생성자
		name = "";
		manufacturer = "";
		price = 0;
	}
	Product(string n, string m, int p, int y, int mo, int d) : Date(y, mo, d) {// 인수 6개를 받는 생성자. 년, 월, 일은 부모 클래스의 생성자 호출
		name = n;
		manufacturer = m;
		price = p;
	}
	void setProduct(string n, string m, int p, int y, int mo, int d) {// 상품명, 제조사, 가격, 년, 월, 일을 함수 내에서 직접 초기화
		name = n;
		manufacturer = m;
		price = p;
		setYear(y);
		setMonth(mo);
		setDay(d);
	}
	void setName(string n) {// 상품명에 대한 설정자
		name = n;
	}
	void setManufacturer(string m) {// 제조사에 대한 설정자
		manufacturer = m;
	}
	void setPrice(int p) {// 가격에 대한 설정자
		price = p;
	}
	string getName() {// 상품명에 대한 접근자
		return name;
	}
	string getManufacturer() {// 제조사에 대한 접근자
		return manufacturer;
	}
	int getPrice() {// 가격에 대한 접근자
		return price;
	}
	void display() { // 객체의 정보를 출력하는 함수
		cout << "Product Name: " << name << endl;
		cout << "Company: " << manufacturer << endl;
		cout << "Price: " << price << endl;
		cout << "Production Date: " << getYear() << "." << getMonth() << "." << getDay() << endl;
	}
};

int main() {
	Product* p = new Product;		//객체생성
	p->setProduct("Saewookkang", "Nongshim", 700, 2011, 4, 21);
	//상품명, 제조사, 가격, 제조년월일출력
	p->display();
	Product p1("Homerun Ball", "Lotte", 1200, 2011, 4, 21);
	p1.display();//객체생성
	delete p;	//객체소멸
	return 0;
}