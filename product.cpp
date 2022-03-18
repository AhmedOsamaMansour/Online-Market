#include "product.h"
#include <iostream>
#include <string>

using namespace std;

product::product() {
	++k;
	id = k;
}
void product::Product_data(int sid) {
	cout << "product ID is :" << id << endl;
	cout << "enter name of product" << endl;
	cin >> productName;
	cout << "enter category of product" << endl;
	cin >> category;
	cout << "enter price" << endl;
	cin >> price;
	seller_id = sid;
}
void product::display_data() {
	cout << "id :" << id << endl << "price :" << price << endl << "name of product :" << productName << endl << "Seller id :" << seller_id << endl;
	cout << "---------------------------------" << endl;
}
void product::setSellerID(int id) {
	seller_id = id;
}
string product::get_category() {
	return category;
}