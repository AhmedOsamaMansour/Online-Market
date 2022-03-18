#pragma once
#include <string>
using namespace std;

class product
{
public:
	static int k;
	double price;
	int id;
	string category;
	string productName;
	int seller_id;
public:
	product();
	void Product_data(int sid);
	void display_data();
	void setSellerID(int id);
	string get_category();
};