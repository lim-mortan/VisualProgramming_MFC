#pragma once
#include <iostream>
#include <string>
using namespace std;
class lhj
{
private:
	string Accountnum;
	int Balance;
	double Interestrate;
	string Name;
	string Company;
	string Adress;
	string PhoneNum;
	string FaxNum;
	string Email;
public:
	lhj();
	~lhj();
	void Datainput();
	void DataShow();
	int Deposit(int num);
	int Withdraw(int num);
	void Estimate(const char a[7], const char b[7]);
};


