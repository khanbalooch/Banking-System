
//Name	:Muhammad Ibrahim
//Roll No: 13i-1821

#ifndef Ibrahim
#define Ibrahim
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/*_______________________________________________________________________________________________________________________________________________*/

class Account
{

	int accno;

	int acctype; //          0   =>   current acc       //    1   =>    saving acc
  public:
	void displayAcctype();
	void setAccount(int aacno, int acctype);
	void setAccno(int accno);
	void setAcctype(int acctype);
	int getAccno();
	int getAcctype();
	void displayAcc();
};
/*____________________________________________________________________________________________________________________________________________*/

class Name
{

	string firstname;

	string middlename;

	string lastname;

  public:
	void setName(string name1, string name2, string name3);
	void setFirstname(string firstname);
	void setMiddlename(string middlename);
	void setLastname(string lastname);
	string getFirstname();
	string getMiddlename();
	string getLastname();
	void displayFirstname();
};
/*____________________________________________________________________________________________________________________________________________*/

class Customer
{
  public:
	Name *name;

	string cnic;

	string address;

	string telephone;

	Account *acc;

	string dob;

	Customer()
	{ //constructor

		name = new Name;

		acc = new Account;
	}

	void setCustomer(string firstname, string middlename, string lastname, int accno, int acctype, string dob, string cnic,
					 string address, string telephone);

	~Customer()
	{ //destructor

		delete name;

		delete acc;
	}
};
/*______________________________________________________________________________________________________________________________________________*/
class Time
{

	int day;

	int month;

	int year;

  public:
	void setTime();
	void displayTime();
};
/*_______________________________________________________________________________________________________________________________________________*/
class Transaction
{

	Time *t;
	int type;
	double amount;
	double remainingBalance;
	static int counter;
	int count;

  public:
	Transaction()
	{ //constructor

		count = Transaction::counter;
		counter++;

		t = new Time;
	}
	int getCount();
	int getType();
	double getAmount();
	double getRemainingbalance();
	void setType(int tt);
	void setAmount(double tt);
	void withDraw(double amount, double pblnc);
	void add(double amount, double pblnc);
	void setTransaction(double amount, double pblnc, int tt);
	void displayTransaction();
	void displayTime();

	~Transaction() { delete t; } //destructor
};
/*_____________________________________________________________________________________________________________________________________________*/
class FBS
{
  public:
	Customer *customer;

	Transaction *transaction;

	FBS()
	{ //constructor

		customer = new Customer;

		transaction = new Transaction[100];
	}

	void setFBS(string firstname, string middlename, string lastname, int accno, int acctype, string dob,
				int balance, string cnic, string address, string telephone);

	void displayTransaction(int count);

	~FBS()
	{ //destructor

		delete customer;
		delete transaction;
	}
};
#endif
