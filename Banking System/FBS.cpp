//Name	:Muhammad Ibrahim
//Roll No: 13i-1821

#include "FBS.h"

int Transaction::counter = 0; //Not a gloabal variable A static variable initializing

/*******************************************************************************************************************************/
//                   setters and getters   for class   Account
/******************************************************************************************************************************/

void Account::setAccount(int accno, int acctype)
{

	setAccno(accno);

	setAcctype(acctype);
}

/*********************************************************************************************************************************/

void Account::setAccno(int accno)
{

	this->accno = accno;
}

/*************************************************************************************************************************************/

void Account::setAcctype(int acctype)
{

	this->acctype = acctype;
}

/**************************************************************************************************************************************/

int Account::getAccno()
{

	return accno;
}

/******************************************************************************************************************************************/

int Account::getAcctype()
{

	return acctype;
}
/*******************************************************************************************************************************************/
void Account::displayAcc()
{

	cout << "Account No : " << getAccno() << "\nAccount type : ";

	if (getAcctype())
	{

		cout << "saving Account ";
	}

	else
	{

		cout << "current Account ";
	}
}

/************************************************************************************************************************************************/

void Account::displayAcctype()
{
	if (getAcctype())
	{

		cout << "saving Account ";
	}

	else
	{

		cout << "current Account ";
	}
}

/************************************************************************************************************************************************/
//                           setters and getters for class Name
/***********************************************************************************************************************************************/

void Name::setName(string name1, string name2, string name3)
{

	setFirstname(name1);

	setMiddlename(name2);

	setLastname(name3);
}

/***********************************************************************************************************************************************/
void Name::setFirstname(string firstname)
{

	this->firstname = firstname;
}
/**********************************************************************************************************************************************/
void Name::setMiddlename(string middlename)
{

	this->middlename = middlename;
}
/**********************************************************************************************************************************************/
void Name::setLastname(string lastname)
{

	this->lastname = lastname;
}
/***********************************************************************************************************************************************/
string Name::getFirstname()
{

	return firstname;
}
/**********************************************************************************************************************************************/
string Name::getMiddlename()
{

	return middlename;
}
/**********************************************************************************************************************************************/
string Name::getLastname()
{

	return lastname;
}
/***********************************************************************************************************************************************/
void Name::displayFirstname()
{

	cout << getFirstname();
}
/*******************************************************************************************************************************************/
//				setters and getters for class Customer
/*******************************************************************************************************************************************/

void Customer::setCustomer(string firstname, string middlename, string lastname, int accno, int acctype, string dob, string cnic,
						   string address, string telephone)
{

	name->setName(firstname, middlename, lastname);

	acc->setAccount(accno, acctype);

	this->dob = dob;

	this->telephone = telephone;

	this->address = address;

	this->cnic = cnic;
}

/******************************************************************************************************************************************/
//		setters  and getters for class Time
/******************************************************************************************************************************************/
void Time::setTime()
{

	time_t t = time(0);

	struct tm *w = localtime(&t);

	day = w->tm_mday;

	month = w->tm_mon + 1;

	year = w->tm_year + 1900;
}
/******************************************************************************************************************************/
void Time::displayTime()
{

	cout << day << "-" << month << "-" << year;
}

/*******************************************************************************************************************************************/
//		setters and getters for class Transaction
/*******************************************************************************************************************************************/
void Transaction::setType(int tt)
{

	type = tt;
}

/**********************************************************************************************************************************/
void Transaction::setAmount(double amount)
{

	this->amount = amount;
}

/**************************************************************************************************************************************/

void Transaction::withDraw(double amount, double pblnc)
{

	int sc = 0;

	int gt = 0;

	if (amount >= 5000)
	{
		sc = (amount / 100) * 0.2;
	}

	if (amount >= 50000)
	{
		gt = (amount / 100) * 2.5;
	}

	this->remainingBalance = pblnc - amount - sc - gt;

	cout << "Transaction completed successfully\n";

	cout << "Remaining Balance is : " << remainingBalance << endl;

	cout << "Serice charges :" << sc << endl;

	cout << "Govt Tax : " << gt << endl;
}

/********************************************************************************************************************************************/

void Transaction::add(double amount, double pblnc)
{

	this->remainingBalance += amount + pblnc;

	cout << "Amount deposited successfully !\n";

	cout << "New Balance is : " << this->remainingBalance << endl;
}

/***************************************************************************************************************************************/

void Transaction::setTransaction(double amount, double pblnc, int tt)
{

	setType(tt);

	setAmount(amount);

	if (tt == 0)
	{ //0 deposition

		add(amount, pblnc);
	}

	else
	{
		withDraw(amount, pblnc);
	}

	t->setTime();
}
/****************************************************************************************************************************************/

int Transaction::getCount() { return count; }

int Transaction::getType() { return type; }

double Transaction::getAmount() { return amount; }

double Transaction::getRemainingbalance() { return remainingBalance; }

void Transaction::displayTime() { t->displayTime(); }
/******************************************************************************************************************************************/
//		setters and getters and class
/********************************************************************************************************************************************/

void FBS::setFBS(string firstname, string middlename, string lastname, int accno, int acctype, string dob,
				 int balance, string cnic, string address, string telephone)
{

	customer->setCustomer(firstname, middlename, lastname, accno, acctype, dob, cnic, address, telephone);
}

/**************************************************************************************************************************************/
void FBS::displayTransaction(int count)
{

	cout
		<< "Transaction History\n***********************************************************************\n"
		<< "Date                tran type              Amount                    Rem Balance            \n";
	for (; count > -1; count--)
	{

		transaction[count].displayTime();

		if (transaction[count].getType())
		{
			cout << "                withdraw";
		}
		else
		{
			cout << "                 Deposition";
		};

		cout << "             " << transaction[count].getAmount();

		cout << "             " << transaction[count].getRemainingbalance();
		cout << endl;
	}
}
/*********************************************************************************************************************************************/
