#include <iostream>
#include <assert.h>
#include <vector>
//#include <stack>
//#include <queue>
#include <string>
#include <set>
//#include "Customer.cpp"
#include "seller.h"
#include "Customer.h"
#include "product.h"

#include <windows.h>
#define color(i) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(i));

using namespace std;

vector <product> p1;
vector <seller> V;
vector <Customer> C;
// seller
void add_product(int sellerID);
// Main Menu
void main_menu();
//customer
void display_category(Customer c1);
//head program
void showtitle();

int Customer::i = 0;
int seller::j = 0;
int product::k = 0;

set<string>categories;
int pro = 0;

int main() {
	showtitle();
	main_menu();
	system("pause");
	return 0;
}
void showtitle()
{
	system("CLS");
	color(4);
	cout << "\t\t\t\t\t  -----------------------------------\n";
	cout << "\t\t\t\t\t  |                                 |\n";
	cout << "\t\t\t\t\t  | << Online Market Application >> |\n";
	cout << "\t\t\t\t\t  |                                 |\n";
	cout << "\t\t\t\t\t  |============= Names =============|\n";
	cout << "\t\t\t\t\t  |                                 |\n";
	cout << "\t\t\t\t\t  |1- Ahmed Mabrouk Fekry           |\n";
	cout << "\t\t\t\t\t  |2- Ahmed Osama Mansor            |\n";
	cout << "\t\t\t\t\t  |3- Ahmed Mohammed Abu Alftouh    |\n";
	cout << "\t\t\t\t\t  |4- Ahmed Magdy Ahmed Ali         |\n";
	cout << "\t\t\t\t\t  |5- Bassam Mohammed               |\n";
	cout << "\t\t\t\t\t  |6- Kamal Aboelkhier              |\n";
	cout << "\t\t\t\t\t  -----------------------------------\n\n\n";
	color(14);   //12 red  14 yellow    4 reeed    10  green
}
void main_menu() {
	bool flag = false;
	//cout << "****************************************************** Hello ******************************************************" << endl;
	while (!flag) {

		cout << "1- Seller					 " << "2- Customer					    " << "3- Exit" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{	//seller
			seller s1;
			cout << "Hello Seller" << endl;
			int RegisterORlogin;
			cout << "Enter 1 if You have an account. " << "  " << "Enter 2 if You don't have an account" << endl;
			cin >> RegisterORlogin;
			bool LoggedIn = false;
			//Register a new Account
			int sellerID;
			if (RegisterORlogin == 2) {
				s1.seller_information();
				V.push_back(s1);
				cout << "Your account was added!" << endl;
				break;
			}
			//log in				  

			else if (RegisterORlogin == 1) {
				seller::j--;
				while (!LoggedIn) {
					string email;
					string password;
					cout << "Enter Your email : " << endl;
					cin >> email;
					cout << "Enter Your Password : " << endl;
					cin >> password;

					for (int i = 0; i < V.size(); i++)
					{
						if (V[i].get_email() == email && V[i].get_Password() == password)
						{
							LoggedIn = true;
							cout << "Welcome " << V[i].get_Name() << endl;
							sellerID = V[i].get_ID();
							break;
						}
					}
					if (!LoggedIn)
					{
						int TryOrExit;
						cout << "Wrong ID or Password " << endl << "enter 1 to try again Or 2 to Exit" << endl;
						cin >> TryOrExit;
						if (TryOrExit == 2)
							break;
					}
				}
			}
			if (LoggedIn)
				add_product(sellerID);

			break;
		}

		case 2:
		{
			//customer
			Customer c1;
			cout << "Hello customer" << endl;
			int RegisterORlogin;
			cout << "Enter 1 if You have an account. " << "  " << "Enter 2 if You don't have an account" << endl;
			cin >> RegisterORlogin;
			bool LoggedIn = false;
			if (RegisterORlogin == 2) {
				c1.customer_information();
				C.push_back(c1);
				cout << "Your account was added!" << endl;
				break;
			}
			else if (RegisterORlogin == 1)
			{
				Customer::i--;
				while (!LoggedIn)
				{

					string email;
					string password;
					cout << "Enter Your email : " << endl;
					cin >> email;
					cout << "Enter Your Password : " << endl;
					cin >> password;

					for (int i = 0; i < C.size(); i++)
					{
						if (C[i].get_email() == email && C[i].get_password() == password)
						{
							LoggedIn = true;
							cout << "Welcome " << C[i].get_name() << endl;
							c1 = C[i];
							break;
						}
					}
					if (!LoggedIn)
					{
						int TryOrExit;
						cout << "Wrong ID or Password " << endl << "enter 1 to try again Or 2 to Exit" << endl;
						cin >> TryOrExit;
						if (TryOrExit == 2)
							break;
					}
				}
				if (LoggedIn) {
					int s;
					int decision;
					cout << "1- Enter Market      2-Show cart " << endl;
					cin >> decision;
					if (decision == 2)
					{
						c1.showCart();
					}
					else if (decision == 1) {
						display_category(c1);
					}
				}
			}
			break;

		}
		case 3:
		{
			flag = true;
			break;
		}
		}
	}
}
void add_product(int sellerID) {
	color(12);
	cout << "1- Add Product   " << "2- Exit" << endl;
	int choice;
	cin >> choice;
	bool Exit = false;
	while (Exit == false)
	{
		switch (choice) {
		case 1: {
			product p;
			p.Product_data(sellerID);
			p1.push_back(p);
			categories.insert(p.get_category());
			pro++;
			//p.display_data();
			break;
		}
		default: {
			Exit = true;
			break;
		}

		}
		if (Exit)
			break;
		color(14);
		string addanotherproduct;
		cout << "Do You want to add another product (y/n)" << endl;
		cin >> addanotherproduct;
		while (addanotherproduct != "y" && addanotherproduct != "n")
		{
			cout << "Please enter y or n" << endl;
			cin >> addanotherproduct;
		}
		if (addanotherproduct == "n")
			Exit = true;
	}
}
void display_category(Customer c1) {
	color(10);
	bool flag11 = false;
	while (!flag11)
	{
		if (pro > 0) {
			int j = 1;
			for (auto i : categories)
			{
				cout << j << " -" << i << endl;
				j++;
			}
		}
		else {
			cout << "There is no product" << endl;
			main_menu();
		}
		int tempcounter;
		cout << "Enter category number :" << endl;
		cin >> tempcounter;
		int counter = 1;
		vector <product> choosenCategory;
		for (auto i : categories)
		{
			if (tempcounter == counter)
			{
				//int itemsCounter = 1;
				for (int x = 0; x < p1.size(); x++)
				{
					if (p1[x].get_category() == i)
					{
						choosenCategory.push_back(p1[x]);
					}
				}
				break;
			}
			else
			{
				counter++;
			}
		}
		for (int item = 0; item < choosenCategory.size(); item++)
		{
			cout << "Item " << item + 1 << " Data : " << endl;
			choosenCategory[item].display_data();
		}

		bool flag = false;
		while (!flag) {
			int ElementToAdd;
			cout << "Enter Element number you want to add to your cart " << endl;
			cin >> ElementToAdd;
			c1.AddtoCart(choosenCategory[ElementToAdd - 1]);
			cout << "Element is added to your Cart" << endl;
			cout << "1-back to shop    2- show Cart    3- back to main menu" << endl;
			int decision;
			cin >> decision;
			if (decision == 1)
			{
				flag = true;
			}
			else if (decision == 2) {
				c1.showCart();
				flag = true;
				flag11 = true;
			}
			else
			{
				flag = true;
				flag11 = true;
			}
		}

	}
}
