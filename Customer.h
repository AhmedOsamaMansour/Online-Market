#pragma once
#include <iostream>
#include <vector>
#include "product.h"
using namespace std;
class Customer
{
public:
	int id;
	static int i;
	string name;
	string address;
	string phone_number;
	string customer_card;
	string email;
	string password;
	vector<product> Cart;

public:

	Customer();
	void customer_information();
	void display_customer_information();
	string get_password();
	string get_name();
	string get_email();
	void AddtoCart(product p);
	void showCart();
	int get_id();

};


