#ifndef P_3_H_2021_12_06
#define P_3_H_2021_12_06

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using std::string;
using std::istream;

/**
@class Item

@brief Stores item information

Stores the items code, name and quick key
*/

class Item {
private:
	/** Code for the item */
	std::string itemCode;
	/** Name of the item */
	std::string itemName;
	/** Quick key for the item*/
	char quickKey;

public:

	/**
	@brief Constructor for Item

	Constructor for item that takes the code,name, and quick key as parameters.

	@param nItemCode code for our item
	@param nItemName name of our item
	@param nQuickKey quick key for our item

	Test 1:

		Input: 3204 Ice Cream a
		Output: 3204 Ice Cream a

	Test 2:

		Input: Corn 1
		Output: JNK Corn \\0

	Test 3:

		Input: 1234  2
		Output: 1234 Unknown 2
	*/
	Item(std::string nItemCode, std::string nItemName, char nQuickKey);

	/**
	@brief Gets Item code

	Gets the Item's code and holds it as a constant varible
	*/
	std::string getItemCode() const;

	/**
	@brief Gets Item name

	Gets the Item's name and holds it as a constant varible
	*/
	std::string getName() const;

	/**
	@brief Gets Item quick key

	Gets the Item's quick key and holds it as a constant varible
	*/
	char getQuickKey() const;

	/**
	@brief Sets Item quick key

	Updates the quick key from the item.

	@param nQuickKey the quick key that will replace the old key

	Test 1:

		Input: A
		Output: A

	Test 2:

		Input: \\0
		Output: \\0

	Test 3:

		Input: 1
		Output: null
	*/
	void updateQuickKey(char nQuickKey);

};

/**
@class Persona

@brief Stores persona information

Stores the a code, id, and 5 slots that could contain items.
*/

class Persona {
private:
	/** Code for the persona */
	std::string personaCode;
	/** Id number */
	std::string personaId;
	/** Array of pointers */
	Item* itemSlots[5];

public:

	/**
	@brief Default Constructor for persona

	Creates a default constructor for perosna that takes no
	*/
	Persona();

	/**
	@brief Constructor for persona

	Creates a constructor for person that takes the code and id as parameters

	@param nPersonaCode code for our characters persona
	@param nPersonaId id for our characters persona
	*/
	Persona(std::string nPersonaCode, std::string nPersonaId);

	/**
	@brief Copy Constructor for Persona

	Creates a Copy constructor for persona that copys the parameter

	@param persona the new persona that is created


	Test 1:

		Input:

			Persona p1(MON, rabbit_09)

		Output:

			Persona p1(MON, rabbit_09)
	Test 2:

		Input:

			Persona p1(Null)

		Output:

			nullpointer
	*/
	Persona(const Persona& persona);

	/**
	@brief Assignment Operator

	Assigns a persona object to a another persona

	@param p persona that is created

	Test 1:

		Input:

			p1 = p2

		Output:

			p2
	Test 2:

		Input:

			p3 = p4

		Output:

			p4
	*/
	Persona& operator=(const Persona& p);

	/**
	@brief Insertion operator overload

	Creates a new insertion operator overload

	@param out where the persona is being written out to
	@param p persona that is created

	Test 1:

		Input:

			<< p2

		Output:

			p2 formatted contents

	Test 2:

		Input:

			<< p3

		Output:

			p3 formatted contents

	*/
	friend std::ostream& operator<<(std::ostream& out, const Persona& p);

	/**
	@brief Extraction operator overload

	Creates a new insertion operator overload

	@param in where the persona is being read from
	@param p persona that is created

	Test 1:

		Input:

			cInput << "straw_2121 MON pig_1001 ALL"
			cInput >> p3

		Output:

			straw_2121 MON pig_1001 ALL

	Test 2:

		Input:

			cInput << "blade_1345 WPN Q"
			cInput >> p3

		Output:

			blade_1345 WPN Q

	*/
	friend std::istream& operator>>(std::istream& in, Persona& p);

	/**
	@brief Deconstructor for persona

	Creates a deconstructor for persona
	*/
	~Persona();

	/**
	@brief Gets persona code

	Gets the persona code and holds it as a constant varible
	*/
	std::string getPersonaCode() const;

	/**
	@brief Gets persona id

	Gets the persona id and holds it as a constant varible
	*/
	std::string getId() const;

	/**
	@brief Gets item from the persona

	Gets the item from the persona and returns it as a constant Item pointer

	@param slot where the item is inside the array
	*/
	const Item* getItem(int slot) const;

	/**
	@brief Adds item

	Adds an item to the persona and puts it in the first empty position in the array

	@param nItemCode
	@param nItemName
	@param nQuickKey

	Test 1:

		Input: 39238 Acorn A
		Output: 39238 Acorn A

	Test 2:

		Input: empty
		Output: false, program crashes

	Test 3:

		Input: 1208 .45 cal bullet c
		Output: 1208 .45 cal bullet c

	Test 4:

		Input: 1111 Stick S
		Output: 1111 Stick S

	Test 5:

		Input: 8765 Health Potion P
		Output: 8765 Health Potion P

	Test 6:

		Input: 12987 Hat \\o
		Output: 12987 Hat \\o
	*/
	bool addItem(std::string nItemCode, std::string nItemName, char nQuickKey);

	/**
	@brief Removes an item

	Removes an item from the persona if there is one at the slot position

	@param nSlot slot to free up

	Test 1:

		Input: 10872 Snow S
		Output: nullPtr

	Test 2:

		Input: 12093 Item A
		Output: nullPtr

	Test 3:

		Input: nullPtr
		Output: false, program crashes
	*/
	bool removeItem(int nSlot);

	/**
	@brief Counts the items

	Counts how many items are inside the persona

	Test 1:

		Input: array has four values
		Output: count = 4

	Test 2:

		Input: array has two values
		Output: count = 2

	Test 3:

		Input: array has no items
		Output: count = 0
	*/
	int countItems();

	/**
	@brief Returns Item position

	Returns Item position with its corresponding quick key

	@param fQuickKey

	Test 1:

		Input:

		item1(1409 item a B)
		item2(1928 item b A)
		item3(19876 item c C)

		findByKey('A')

		Output:
		2

	Test 2:

		Input:

		item1(1409 item a Q)
		item2(1928 item b A)
		item3(19876 item c L)

		findByKey('L')

		Output:
		3
	Test 3:

		Input:

		item1(1409 item a B)
		item2(1928 item b A)
		item3(19876 item c C)

		findByKey('Z')

		Output:
		-1
	*/
	int findByKey(char fQuickKey);

	/**
	@brief updates quick key

	Looks through items and changes the old key with a new one

	@param oldQuickKey quick key before its updated
	@param newQuickKey quick key after its been updated

	Test 1:

		Input:

		Item it1(1234 item Q)

		p1.updateKey(Q, P)

		Output:

		1234 item P

	Test 2:

		Input:

		Item it1(1256 Ice Cream X)
		p1.updateKey(X, C)

		Output:

		1256 Ice Cream C

	Test 3:

		Input:

		Item it1(1345 Dart L)
		p1.updateKey(L, C)

		Output:

		1345 Dart C
	*/
	void updateKey(char oldQuickKey, char newQuickKey);

};

/**
@class PersonaList

@brief Stores information inside an array

Stores persona objects inside a dynamic array.
*/

class PersonaList {
private:

	/** Persona Pointer array */
	Persona* personaArray;

	/** Current size of the pointer array */
	int currentSize;

	/** The maximum size of the array */
	int maxSize;

	/** Private function that grows the array but returns nothing */
	void growArray();

public:

	/**
	@brief Constructor for PersonaList

	Creates a constructor for PersonaList that takes no parameters
	*/
	PersonaList();

	/**
	@brief Destructor for PersonaList

	Creates a destructor for PersonaList
	*/
	~PersonaList();

	/**
	@brief getPersonaCoutn

	Returns the number of personas in the array.
	*/
	int getPersonaCount() const;

	/**
	@brief getPersona

	Gets the persona at the position.

	@param personaPosition where the persona is
	*/
	Persona* getPersona(int personaPosition);

	/**
	@brief getPersona

	Returns a const persona pointer

	@param pos where the persona is inside the array
	*/
	const Persona* getPersona(int pos)const;

	/**
	@brief addPersona

	Add a new persona to the end of the list

	@param newPersona the persona that is being created

	Test 1:

		Input:

			listInput << "cheese_2314 ITM whistle_1345 WOP"

		Output:

			Add Persona:
			cheese_2314 ITM
			whistle_1345 WOP

	*/
	void addPersona(Persona newPersona);

	/**
	@brief findPersona

	Finds persona by the id and returns a pointer to it.

	@param personaId the id of the persona to be returned

	Test 1:

		Input:

			personas.findPersona("person_4087")

		Output:

			finds: person_4087

	Test 2:

		Input:

			personas.findPerson(ball_1111)

		Output:

			nullptr

	*/
	Persona* findPersona(string personaId);

	/**
	@brief resetKeyBindings

	Finds personas with the same quick key and resets it to \\0

	@param quickKey the quick key that will be reset to \\0

	Test 1:

		Input:

		charKey p

			sword_1345 P

		Output:

			sword_1345 \\0

	*/
	int resetKeyBindings(char quickKey);

	/**
	@brief resetList

	Resets the list and makes it empty

	Test 1:

		Input:

			sword_1234 Q
			wood_3456 Q
			pot_1670

		Output:

			0
	*/
	void resetList();
};

/**
@class PersonaUtil

@brief Processes the persona list

Stores persona list and processes commands to modify the list
*/

class PersonaUtil {
private:

	/** Persona Pointer array */
	PersonaList* groupPointer;

	/**
	@brief command_persona

	Allows the use of the persona command

	@param in takes the input as an istream
	*/
	void command_persona(istream& in);

	/**
	@brief command_additem

	Allows the use of the additem command

	@param in takes the input as an istream
	*/
	void command_additem(istream& in);

	/**
	@brief command_additem

	Allows the use of the removeitem command

	@param in takes the input as an istream
*/
	void command_removeitem(istream& in);

public:

	/**
	@brief Constructor for PerosnaUtil

	Creates a constructor for PersonaList that takes on parameter

	@param groupPointer points to the perosna list pointer
	*/
	PersonaUtil(PersonaList* groupPointer);

	/**
	@brief gets the persona pointer

	Returns a pointer to the persona's class list
	*/
	PersonaList* getPersonas();

	/**
	@brief processes commands

	Processes the commands to add/modify the persona list

	@param in the istream used
	*/
	void loadPersonas(istream& in);

	/**
	@brief converts persona list to a string

	Returns the persona list as a string that will be outputted
	*/
	string savePersonas();

	/**
	@brief changes items inside the array

	Generates a final report of how many personas where changed

	@param list keys reset to blackslash 0
	@param size the size of the array
	*/
	string clearKeys(char list[], int size);
};

#endif // !P_3_H_2021_12_06