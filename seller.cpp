#include "seller.h"
#include <iostream>
#include <string>
using namespace std;

seller::seller() {
	++j;
	id = j;
}
void seller::seller_information() {
	cout << "your ID is: " << id << endl;
	cout << "enter your name" << endl;
	cin >> name;
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
	cout << "enter your password" << endl;
	cin >> password;
	while (password.size() < 6)
	{
		cout << "The password must be at least 6 characters" << endl;
		cout << "enter your password" << endl;
		cin >> password;
	}
}
void seller::display_seller_information() {
	cout << "Name :" << name << endl << "id :" << id << endl << "email :" << email << endl;
}
int seller::get_ID() {
	return id;
}
string seller::get_Password() {
	return password;
}
string seller::get_Name() {
	return name;
}
string seller::get_email() {
	return email;
}



