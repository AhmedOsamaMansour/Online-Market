#include "Customer.h"
#include "product.h"
#include <iostream>
using namespace std;




Customer::Customer()
{

	++i;
	id = i;

}

void Customer::customer_information() {


	cout << "your id is :  " << id << endl;

	cout << "enter your email" << endl;
	cin >> email;
	bool emailIsValid = false;
	while (!emailIsValid)
	{
		for (int i = 0; i < email.size(); i++)
		{
			if (email[i] == '@')
				for (int j = i; j < email.size(); j++)
				{
					if (email[j] == '.' && j != i + 1)
					{
						string last = email.substr(j);
						if (last == ".com")
						{
							emailIsValid = true;
						}
					}
				}
		}
		if (!emailIsValid)
		{
			cout << "Email must Contain at format ( example@mail.com )" << endl << "enter your email" << endl;
			cin >> email;
		}
	}
	cout << "Enter your password " << endl;
	cin >> password;
	while (password.size() < 6)
	{
		cout << "The password must be at least 6 characters" << endl;
		cout << "enter your password" << endl;
		cin >> password;
	}
	cout << "enter your name" << endl;
	cin >> name;

	cout << "enter your Address" << endl;
	cin >> address;
	cout << "enter your phone number" << endl;
	cin >> phone_number;
	cout << "enter your card number" << endl;
	cin >> customer_card;


}
void Customer::display_customer_information() {
	cout << "Name :" << name << endl << "id :" << id << endl << "Address :" << address << endl << "phone_number :" << phone_number << endl << "card :" << customer_card << endl << "email :" << email << endl;
}
string Customer::get_password() {
	return password;
}

string Customer::get_name() {
	return name;
}

string Customer::get_email() {
	return email;
}
void Customer::AddtoCart(product p) {
	Cart.push_back(p);
}
void Customer::showCart() {
	double price = 0;
	if (Cart.size() == 0)
	{
		cout << "Cart Is Empty !" << endl;
		return;
	}
	for (int i = 0; i < Cart.size(); i++) {
		Cart[i].display_data();
		price += Cart[i].price;
	}
	cout << "Total Price : " << price << endl;
	cout << "1- Confirm buy  2- back" << endl;
	int decision;
	cin >> decision;
	if (decision == 1)
	{
		cout << "Process has done Succesfully ! " << endl;
	}

}