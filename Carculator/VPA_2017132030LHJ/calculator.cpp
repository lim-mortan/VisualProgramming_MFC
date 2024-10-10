#include <iostream>
 

using namespace std;

void add(double* a, double* b);		//더하기 함수는 두개의 포인터 변수 통해 입력값 전달
void sub(double* a, double* b);		//빼기 함수는 두개의 포인터 변수 통해 입력값 전달
void mul(double a, double b);		//곱하기 함수는 두개의 일반 변수를 통해 입력값 전달
void div(double a, double b);		//나누기 함수는 두개의 일반 변수를 통해 입력값 전달

int main() {
	double num1, num2;
	char lhj;
	bool End = false;

	while (!End) {													//탈출방법 추가
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
			cout << "input number %d %d : ";			//두수 입력
			cin >> num1 >> num2;
			add(&num1, &num2);							//포인터를 사용하여 &로 접근
			break;

		case '2':
			cout << "input number %d %d : ";
			cin >> num1 >> num2;
			sub(&num1, &num2);							//포인터를 사용하여 &로 접근
			break;

		case '3':
			cout << "input number %d %d : ";
			cin >> num1 >> num2;
			mul(num1, num2);							//별도의 포인터 필요 없이 double 인자로 진행
			break;

		case '4':
			cout << "input number %d %d : ";
			cin >> num1 >> num2;				
			if (num2 == 0) {													//5번 조건에 나눗셈시분모가 0이면 분모값만 다시 입력받게 진행
				cout << "num2 is 0? please again input num." << endl;			//분모가 0일때 바꿔줌	//이 코드에서는 분모만이 아니라 그냥 다시 입력하게 하였음
				continue;
			}
			div(num1, num2);
			break;
		
		case'5':
			cout << "Quit" << endl;
			break;

		default:
			cout << "invalid warning" << endl;
			continue;									//디폴트 값으로 요청문자 이외의 것은 재입력
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
	cout << "result: " << *a + *b << endl;					//포인터 변수 사용
}

void sub(double* a, double* b) {
	cout << "result: " << *a - *b << endl;					//포인터 변수 사용
}

void mul(double a, double b) {
	cout << "result: " << a * b << endl;					//일반 변수 사용
}

void div(double a,  double b) {
	float result;											//결과값은 소수가 나올수 있으니 result를 float형식으로 변환

	if (b == 0) {											//만약 분모가 0이면 오류 메시지
		cout << "error: num2 = 0..." << endl;
		return;												//다시 요청
	}

	result = a / b;											

	cout << " result : " << result << endl;
}
