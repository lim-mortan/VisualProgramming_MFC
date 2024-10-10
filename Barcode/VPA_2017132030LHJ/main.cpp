#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date() {		//�μ��� ���� �⺻������
		year = 0;
		month = 0;
		day = 0;
	}
	Date(int y, int m, int d) {		//�Ű����� 3�� �޾Ƽ� ��������� ����
		year = y;
		month = m;
		day = d;
	}
	void setYear(int y) { //�� ������
		year = y;
	}
	void setMonth(int m) {//�� ������
		month = m;
	}
	void setDay(int d) {//�� ������
		day = d;
	}
	int getYear() {//�� ������
		return year;
	}
	int getMonth() {//�� ������
		return month;
	}
	int getDay() {//�� ������
		return day;
	}
};

class Product : public Date {// Date Ŭ���� ���
private:
	string name;
	string manufacturer;
	int price;
public:
	Product() {// �μ��� ���� �⺻ ������
		name = "";
		manufacturer = "";
		price = 0;
	}
	Product(string n, string m, int p, int y, int mo, int d) : Date(y, mo, d) {// �μ� 6���� �޴� ������. ��, ��, ���� �θ� Ŭ������ ������ ȣ��
		name = n;
		manufacturer = m;
		price = p;
	}
	void setProduct(string n, string m, int p, int y, int mo, int d) {// ��ǰ��, ������, ����, ��, ��, ���� �Լ� ������ ���� �ʱ�ȭ
		name = n;
		manufacturer = m;
		price = p;
		setYear(y);
		setMonth(mo);
		setDay(d);
	}
	void setName(string n) {// ��ǰ�� ���� ������
		name = n;
	}
	void setManufacturer(string m) {// �����翡 ���� ������
		manufacturer = m;
	}
	void setPrice(int p) {// ���ݿ� ���� ������
		price = p;
	}
	string getName() {// ��ǰ�� ���� ������
		return name;
	}
	string getManufacturer() {// �����翡 ���� ������
		return manufacturer;
	}
	int getPrice() {// ���ݿ� ���� ������
		return price;
	}
	void display() { // ��ü�� ������ ����ϴ� �Լ�
		cout << "Product Name: " << name << endl;
		cout << "Company: " << manufacturer << endl;
		cout << "Price: " << price << endl;
		cout << "Production Date: " << getYear() << "." << getMonth() << "." << getDay() << endl;
	}
};

int main() {
	Product* p = new Product;		//��ü����
	p->setProduct("Saewookkang", "Nongshim", 700, 2011, 4, 21);
	//��ǰ��, ������, ����, ������������
	p->display();
	Product p1("Homerun Ball", "Lotte", 1200, 2011, 4, 21);
	p1.display();//��ü����
	delete p;	//��ü�Ҹ�
	return 0;
}