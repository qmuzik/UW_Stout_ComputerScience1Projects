#ifndef LAB_H_2021_11_29
#define LAB_H_2021_11_29

#include <iostream>
#include <iomanip>
#include <string>

/**
@class Item

@brief Stores item information

Stores an items id, date, and name.

Test 1:

	Input: 4210 2021-21-11 Milk
	Output: 4210 2021-21-11 Milk

Test 2:

	Input: 1973 2019-13-08 Eggs
	Output: 1973 2019-13-08 Eggs

Test 3:

	Input: 2091 2020-08-01 Bread
	Output: 2091 2020-08-01 Bread

*/

class Item {
private:
	/** Id number for item */
	int id;
	/** Date that an item was ordered */
	std::string date;
	/** Name of item */
	std::string name;

public:

	/**
	@brief Default constructor for Item

	Default constructor for item that sets the Id, Date and Name to zero.
	*/
	Item();

	/**
	@brief Constructor that changes values in Item

	Constructor that changes the values of Id, date, and name

	@param nId The new employee id number
	@param nDate The new date
	@param nName The new name
	*/
	Item(int nId, std::string nDate, std::string nName);

	/**
	@brief Gets Item Id

	Gets the Item's id and holds it as a constant varible
	*/
	int getItemId() const;

	/**
	@brief Gets Item Date

	Gets the Item's Date and holds it as a consant varible
	*/
	std::string getDate() const;

	/**
	@brief Gets the items name

	Gets the items name and holds it as a constant varible
	*/
	std::string getName() const;

};

/**
@class Order

@brief Stores order items

Test 1:

	Input:
	Order order1;

	order1.addItem(5203, "2019-11-14", "Stuff");
	order1.addItem(3212, "2020-11-12", "More Stuff");
	order1.addItem(2001, "2017-01-16", "Birthday Cake");
	order1.addItem(1212, "2016-03-31", "Book");
	order1.addItem(1234, "2013-09-12", "Nothing");

	Output:

	0     5202 2019-11-14 Stuff
	1     2001 2017-01-16 Birthday Cake
	2     1212 2016-03-31 Book
	3     1234 2013-09-12 Nothing
	4    53535 2016-12-08 More Stuff


Test 2:

	Input:

	order1.addItem(1123, "2021-12-02", "Marshmallows");
	order1.addItem(2716, "2020-12-02", "Grahamn Crackers");

	Output:

	0     1123 2021-12-02 Marshmallows
	0     2716 2021-12-02 Grahamn Crackers

Test 3:

	Input:

	order1.addItem(0116, "2021-12-01", "Jelly Beans");
	order1.addItem(4085, "2020-12-02", "Hershey Kisses");
	order1.addItem(8345, "2021-12-03", "Andes Mints");

	Output:

	0     0116 2021-12-01 Jelly Beans
	1     4085 2021-12-02 Hershey Kisses
	2	  8345 2021-12-03 Andes Mints

*/

class Order {
private:
	/** Array of Items */
	Item items[10];
	/** Items that are currently in the array */
	int count;

public:

	/**
	@brief Constructor for Order

	Creates a constructor called order
	*/
	Order();

	/**
	@brief gets the number of items

	Counts the number of items inside the array
	*/
	int getCount() const;

	/**
	@brief gets the Item

	@param itemPosition postion of item in our array

	Finds the item inside the array and returns it
	*/
	Item getItem(int itemPosition) const;

	/**
	@brief adds an item

	@param id The id number of our item
	@param date Date it was ordered as a string
	@param name Name of our item

	Adds another item to the array
	*/
	bool addItem(int id, std::string date, std::string name);

	/**
	@brief finds the item

	@param id The id of our item
	Finds the item inside the array by using its Id number
	*/
	int findItem(int id) const;

	/**
	@brief removes an item

	@param id The id of our iteam

	Finds the item inside the array and removes it
	*/
	bool removeItem(int id);

};

/**
@brief insertion operator for the item class

@param out used as an ostream
@param item prints the content in our item class

Creates an insertion operator for item class that allows operation overloading
*/
std::ostream& operator << (std::ostream& out, const Item& item);


/**
@brief insertion operator for the order class

@param out used as an ostream
@param order prints the content in our Order class

Creates an insertion operator for order class that allows operation overloading
*/
std::ostream& operator << (std::ostream& out, const Order& order);

#endif // !LAB_H_2021_11_29

