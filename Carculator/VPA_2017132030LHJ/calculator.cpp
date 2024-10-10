#include <iostream>
 

using namespace std;

void add(double* a, double* b);		//���ϱ� �Լ��� �ΰ��� ������ ���� ���� �Է°� ����
void sub(double* a, double* b);		//���� �Լ��� �ΰ��� ������ ���� ���� �Է°� ����
void mul(double a, double b);		//���ϱ� �Լ��� �ΰ��� �Ϲ� ������ ���� �Է°� ����
void div(double a, double b);		//������ �Լ��� �ΰ��� �Ϲ� ������ ���� �Է°� ����

int main() {
	double num1, num2;
	char lhj;
	bool End = false;

	while (!End) {													//Ż���� �߰�
		cout << "              calculator program \n";
		cout << "**************\n";
		cout << "1 . Add\n";
		cout << "2 . Substract\n";
		cout << "3 . Multiply\n";
		cout << "4 . Divide\n";
		cout << "5 . Quit\n";
		cout << "**************\n";
		
		cin >> lhj;							//operator

		switch (lhj) {
		case '1':
			cout << "input number %d %d : ";			//�μ� �Է�
			cin >> num1 >> num2;
			add(&num1, &num2);							//�����͸� ����Ͽ� &�� ����
			break;

		case '2':
			cout << "input number %d %d : ";
			cin >> num1 >> num2;
			sub(&num1, &num2);							//�����͸� ����Ͽ� &�� ����
			break;

		case '3':
			cout << "input number %d %d : ";
			cin >> num1 >> num2;
			mul(num1, num2);							//������ ������ �ʿ� ���� double ���ڷ� ����
			break;

		case '4':
			cout << "input number %d %d : ";
			cin >> num1 >> num2;				
			if (num2 == 0) {													//5�� ���ǿ� �������úи� 0�̸� �и𰪸� �ٽ� �Է¹ް� ����
				cout << "num2 is 0? please again input num." << endl;			//�и� 0�϶� �ٲ���	//�� �ڵ忡���� �и��� �ƴ϶� �׳� �ٽ� �Է��ϰ� �Ͽ���
				continue;
			}
			div(num1, num2);
			break;
		
		case'5':
			cout << "Quit" << endl;
			break;

		default:
			cout << "invalid warning" << endl;
			continue;									//����Ʈ ������ ��û���� �̿��� ���� ���Է�
		}

		char exit;
		cout << "pause?? <y/n>: ";
		cin >> exit;

		while (exit != 'y' && exit != 'n') {
			cout << " please...input 'y' or 'n': ";
			cin >> exit;
		}

		End = (exit == 'y');
	}

	return 0;
}

void add(double* a, double* b) {
	cout << "result: " << *a + *b << endl;					//������ ���� ���
}

void sub(double* a, double* b) {
	cout << "result: " << *a - *b << endl;					//������ ���� ���
}

void mul(double a, double b) {
	cout << "result: " << a * b << endl;					//�Ϲ� ���� ���
}

void div(double a,  double b) {
	float result;											//������� �Ҽ��� ���ü� ������ result�� float�������� ��ȯ

	if (b == 0) {											//���� �и� 0�̸� ���� �޽���
		cout << "error: num2 = 0..." << endl;
		return;												//�ٽ� ��û
	}

	result = a / b;											

	cout << " result : " << result << endl;
}
