#include "lhj.h"

lhj::lhj() : Accountnum(""), Balance(0), Interestrate(0.0), Name(""), Company(""), Adress(""), PhoneNum(""), FaxNum(""), Email("")
{

}
lhj::~lhj()
{

}
void lhj::Datainput()
{
	cout << "******************************" << endl;
	cout << "Input AccountNumber : ";
	cin >> Accountnum;
	cout << endl;
	cout << "Input Balance : ";
	cin >> Balance;
	cout << endl;
	cout << "Input Interestrate per month(%) : ";
	cin >> Interestrate;
	cout << endl;
	cout << "Input Name : ";
	cin >> Name;
	cout << endl;
	cout << "Input Company : ";
	cin >> Company;
	cout << endl;
	cout << "Input Adress : ";
	cin >> Adress;
	cout << endl;
	cout << "Input PhoneNumber : ";
	cin >> PhoneNum;
	cout << endl;
	cout << "Input FaxNumber : ";
	cin >> FaxNum;
	cout << endl;
	cout << "Input Email : ";
	cin >> Email;
	cout << endl;
	cout << "******************************" << endl;
}
void lhj::DataShow()
{
	cout << "-----------------------------" << endl;
	cout << "|| ACCOUNT INFORMATION OF YOURS || " << endl;
	cout << "AccountNumber : " << Accountnum << endl;
	cout << "Balance : " << Balance << endl;
	cout << "Interestrate per month(%) : " << Interestrate << endl;
	cout << "Name : " << Name << endl;
	cout << "Company : " << Company << endl;
	cout << "Adress : " << Adress << endl;
	cout << "PhoneNumber : " << PhoneNum << endl;
	cout << "FaxNumber : " << FaxNum << endl;
	cout << "Email : " << Email << endl;
	cout << "-----------------------------" << endl;
}
int lhj::Deposit(int num)
{
	cout << "Deposit Money is " << num << "won" << endl;
	return Balance += num;
}
int lhj::Withdraw(int num)
{
	cout << "Withdraw Money is " << num << "won" << endl;
	return Balance -= num;
}
void lhj::Estimate(const char a[7], const char b[7])
{
	int startyear = 0;
	double newbalance = 0.0;
	newbalance = (double)Balance;
	int startmonth = 0;
	int endyear = 0;
	int endmonth = 0;
	int month;
	int i;
	int num = 1000;
	int num2 = 10;
	for (i = 0; i < 4; i++)
	{
		startyear += (a[i] - 48) * num;
		endyear += (b[i] - 48) * num;
		num = num / 10;
	}
	for (i = 5; i < 7; i++)
	{
		startmonth += (a[i] - 48) * num2;
		endmonth += (b[i] - 48) * num2;
		num2 = num2 / 10;
	}
	if (startmonth <= endmonth)
	{
		month = ((endyear - startyear) * 12) + (endmonth - startmonth);
	}
	else
	{
		month = (13 - startmonth + endmonth) + ((endyear - startyear - 1) * 12);
	}
	for (i = 1; i <= month; i++)
	{
		newbalance *= (1 + (Interestrate / 100));
	}
	cout << "Estimate month is while " << a << " to " << b << endl;
	Balance = Balance + (int)newbalance;
}