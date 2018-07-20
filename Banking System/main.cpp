//Name	:Muhammad Ibrahim
//Roll No: 13i-1821

#include <iostream>
#include <string>
#include <ctime>
#include "FBS.h"
using namespace std;
int main()
{
	int *count;
	count = new int[100];
	for (int i = 0; i < 100; i++)
	{
		count[i] = -1;
	}
	FBS *fbs = new FBS[100];
	char ch1;
	int ch2, fbscount = 0, acch, accno, depcount = -1;
	string name1, name2, name3, address, dob, cnic, tlp;
	double balance, amount;

	/************************************************************************************************************************************************/

	do
	{
		cout << "******************Main Menu******************\n"
			 << "Enter your choice\n\n"
			 << "\tA. Create a new account.\n"
			 << "\tB. Operations over existing customers.\n"
			 << "\tC. Generate the list of all customers with accounts"
			 << " and  balance.\n"
			 << "\tD.End Programme.\n\n"
			 << "Enter Here : ";
		cin >> ch1;
		ch1 = toupper(ch1);
		switch (ch1)
		{

		case 'A':
			cout << "Enter first name             :";
			cin.ignore();
			getline(cin, name1);
			cout << "Enter middle name            :";

			cin.ignore();
			getline(cin, name2);
			cout << "Enter last name              :";
			cin.ignore();
			getline(cin, name3);
			cout << "Enter CNIC(00000-0000000-0)  :";
			cin >> cnic;
			cout << "Enter address(H#,St#,sector) :";
			cin.ignore();
			getline(cin, address);
			cout << "Enter telephone Number(04212345):";
			cin.ignore();
			getline(cin, tlp);
			cout << "Enter date of birth(dd-mm-yyyy) : ";
			cin.ignore();
			getline(cin, dob);
			cout << "Choice your account type\n\n"
				 << "\t1.saving account.\n"
				 << "\t0.current account.\n\n"
				 << "Enter Here : ";
			cin >> acch;

			fbs[fbscount].setFBS(name1, name2, name3, fbscount + 1, acch, dob, balance, cnic, address, tlp);

			cout << "******************************\n    Account created\n";
			fbs[fbscount].customer->acc->displayAcc();
			cout << "\nName :";
			fbs[fbscount].customer->name->displayFirstname();
			cout << endl
				 << "CNIC : " << fbs[fbscount].customer->cnic << endl
				 << "Address : " << fbs[fbscount].customer->address << endl;
			fbscount++;
			cout << "******************************\n";
			/**********************************************************************************************************/
			break;
		case 'B':
			do
			{
				cout << "Enter your choice.\n\n"
					 << "\t1. Generate Mini Statement of a Bank Customer.\n"
					 << "\t2. Withdraw money from a customer account.\n"
					 << "\t3. Deposit money.\n"
					 << "\t4. Balance Inquiry.\n"
					 << "\t5. Transaction history.\n"
					 << "\t0. Main Menu.\n\n"
					 << "Enter Here : ";
				cin >> ch2;
				switch (ch2)
				{
				case 1:
					cout << "Account No : ";
					cin >> accno;
					cout << "CNIC       : ";
					cin.ignore();
					getline(cin, cnic);
					for (int i = 0; i <= fbscount; i++)
					{
						if (accno = fbs[i].customer->acc->getAccno())
						{
							if (cnic == fbs[i].customer->cnic)
							{
								fbs[i].displayTransaction(count[i]);
								break;
							}
							else
							{
								cout << "Invalid Account NO or CNIC!\n";
							}
						}
					}

					break;
				case 2:
					cout << "Account No         : ";
					cin >> accno;
					cout << "CNIC               : ";
					cin.ignore();
					getline(cin, cnic);
					cout << "Amount to be drawn : ";
					cin >> amount;
					for (int i = 0; i < fbscount; i++)
					{
						if (accno == fbs[i].customer->acc->getAccno())
						{
							if (cnic == fbs[i].customer->cnic)
							{
								double pblnc;
								if (i == 0 && count[i] == -1)
								{
									pblnc = 0;
								}
								else
								{
									pblnc = fbs[i].transaction[count[i]].getRemainingbalance();
								}
								fbs[i].transaction[count[i] + 1].setTransaction(amount, pblnc, 1);
								count[i] += 1;
								break;
							}
							else
							{
								cout << "Invalid Account or CNIC!\n";
							}
						}
					}
					break;
				case 3:
					cout << "Account No             : ";
					cin >> accno;
					cout << "CNIC                   : ";
					cin.ignore();
					getline(cin, cnic);
					cout << "Amount to be deposited : ";
					cin >> amount;
					for (int i = 0; i < fbscount; i++)
					{
						if (accno == fbs[i].customer->acc->getAccno())
						{
							if (cnic == fbs[i].customer->cnic)
							{
								double pblnc;
								if (i == 0 && count[i] == -1)
								{
									pblnc = 0;
								}
								else
								{
									pblnc = fbs[i].transaction[count[i]].getRemainingbalance();
								}
								fbs[i].transaction[count[i] + 1].setTransaction(amount, pblnc, 0);
								cout << "Previous balance : " << pblnc << endl;
								count[i] += 1;
								break;
							}
							else
							{
								cout << "Invalid Account or CNIC!\n";
							}
						}
					}

					break;
				case 4:
					cout << "Account No     : ";
					cin >> accno;
					cout << "CNIC           : ";
					cin.ignore();
					getline(cin, cnic);
					cout << "Amount : ";
					for (int i = 0; i < fbscount; i++)
					{
						if (accno = fbs[i].customer->acc->getAccno())
						{
							if (cnic == fbs[i].customer->cnic)
							{
								cout << fbs[i].transaction[i].getRemainingbalance();
								break;
							}
							else
							{
								cout << "Invalid Account or CNIC!\n";
							}
						}
					}
					cout << endl;
					break;
				case 5:
					cout << "Account No    : ";
					cin >> accno;
					cout << "CNIC          : ";
					cin.ignore();
					getline(cin, cnic);

					for (int i = 0; i < fbscount; i++)
					{
						if (accno = fbs[i].customer->acc->getAccno())
						{
							if (cnic == fbs[i].customer->cnic)
							{
								fbs[i].displayTransaction(count[i]);
								break;
							}
							else
							{
								cout << "Invlid Account or CNIC!\n";
							}
						}
					}
					cout << endl;

					break;
				};
			} while (ch2 != 0);
			break;
		case 'C':
			cout << "*************************************************************************\n";
			cout << "Name      "
				 << "Account No      "
				 << "Account type       "
				 << "Balance\n";
			for (int i = 0; i < fbscount; i++)
			{
				fbs[i].customer->name->displayFirstname();
				cout << "           "
					 << fbs[i].customer->acc->getAccno() << "             ";
				fbs[i].customer->acc->displayAcctype();
				cout << "       ";
				cout << fbs[i].transaction[count[i]].getRemainingbalance();

				cout << endl;
			}

			break;
		};
	} while (ch1 != 'D');

	delete[] fbs;
	delete[] count;

	return 0;
}
