/**
	@file order.cpp
	@brief stores information about items

	Contains information about items ordered by a company.

	@author Quincy Muzik
	@date 11/29/2021
*/

#include "lab8.h" // Header file 

using std::string;
using std::cin;
using std::cout;
using std::ostream;
using std::left;
using std::right;
using std::setw;

/** Item Class */
Item::Item(int nId, std::string nDate, std::string nName) {
	id = nId;
	date = nDate;
	name = nName;
}

Item::Item() {
	id = -1;
	name = "";
	date = "";
}

int Item::getItemId() const {
	return id;
}

string Item::getDate() const {
	return date;
}

string Item::getName() const {
	return name;
}

/** Order Class */
Order::Order() {
	count = 0;
}

int Order::getCount() const {
	return count;
}

Item Order::getItem(int itemPosition) const {
	if (itemPosition >= 0 && itemPosition < count) {
		return items[itemPosition];
	}

	Item notValidItem;
	return notValidItem;

}

bool Order::addItem(int id, std::string date, std::string name) {

	// Check to see if array is full
	if (count == 10) {
		return false;
	}

	// Declares a new item varible that holds the value of a new item 
	Item newItem(id, date, name);

	// Add item to the array 
	items[count] = newItem;
	count++;
	return true;
}

int Order::findItem(int id) const {


	for (int i = 0;  i < count; i++) {
		if (items[i].getItemId() == id) {
			return i;
		}
	}

	return -1;
}

bool Order::removeItem(int id) {

	// Searches for the position of the item with ID 
	int i = findItem(id);

	if (i == -1) {
		return false;
	}

	count--;

	while (i < count) {
		items[i] = items[i + 1];
		i++;
	}

	return true;
}

/**
@brief insertion operator for the item class

@param out used as an ostream
@param item prints the content in our item class

Creates an insertion operator for item class that allows operation overloading
*/

ostream& operator <<(ostream& out, const Item& item) {
	out << right << setw(8) << item.getItemId() << " "
		<< left << setw(10) << item.getDate() << " " << left << item.getName() << "\n";
	return out;
}

/**
@brief insertion operator for the order class

@param out used as an ostream
@param order prints the content in our Order class

Creates an insertion operator for order class that allows operation overloading
*/

ostream& operator <<(ostream& out, const Order& order) {
	for (int i = 0; i < order.getCount(); i++) {
		out << right << setw(5) << i << " " << order.getItem(i) << "\n";
	}
	return out;
}

//// Used for testing 
//int main() {
//
//	Order order1;
//
//	order1.addItem(5202, "2019-11-14", "Stuff");
//	order1.addItem(2001, "2017-01-16", "Birthday Cake");
//	order1.addItem(1212, "2016-03-31", "Book");
//	order1.addItem(1234, "2013-09-12", "Nothing");
//
//	cout << order1.getCount() << " " << order1.getItem(0) << "\n";
//
//	order1.addItem(53535, "2016-12-08", "More Stuff");
//	cout << order1 << "\n";
//
//	cout << order1.getItem(5) << "\n";
//	cout << order1.findItem(53535) << "\n";
//	cout << order1.removeItem(5202) << "\n";
//
//	cout << order1 << "\n";
//
//}
