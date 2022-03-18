//seller.h
#pragma once
#include <string>
using namespace std;

class seller
{
public:
	static int j;
	string name;
	string email;
	int id;
	string password;
	//int rating;

public:
	seller();
	void seller_information();
	void display_seller_information();
	int get_ID();
	string get_Password();
	string get_Name();
	string get_email();
};

