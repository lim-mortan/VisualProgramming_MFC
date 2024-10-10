#include "lhj.h"

int main(void)
{
	lhj* lhjAccount = new lhj;
	lhjAccount->Datainput();
	lhjAccount->DataShow();
	lhjAccount->Deposit(100000);
	lhjAccount->Withdraw(50000);
	lhjAccount->Estimate("2018-02", "2020-12");
	lhjAccount->DataShow();
	delete lhjAccount;

	return 0;
}