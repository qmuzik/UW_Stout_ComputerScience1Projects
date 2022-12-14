#include <iostream>
#include <string>
#include "game.h"
#include <sstream>
#include <cstdlib>

using namespace std;

int main() {

	// create Item
	Item item1("Item A", 1);
	Item item2;
	Character char1("Steph");
	// give it values
	//item1.setName("Item A");
	//item1.setType(1);
	item2.setName("Hammer");
	char1.setRightHand(item1);
	// print it
	cout << item1 << "\n" << item2;
	cout << "\n" << char1 << "\n";

	CharacterList list;

	for (int i = 0; i < 130; i++) {
		// create a character
		stringstream name;
		name << "Gerry " << i;
		Character tempChar(name.str());
		tempChar.setLevel(rand() % 50 + 1);
		// give the character an item
		Item sword("sword of pitifulness", 0);
		tempChar.setLeftHand(sword);

		// add to the list
		list.addCharacter(tempChar);
	}

	// print all of the characters in list
	for (int i = 0; i < list.getCount(); i++) {
		cout << list.getCharacter(i) << "\n";
	}
	cout << list.getCharacter(400);

	int lowest = list.getLowestLevel();
	cout << "\n\nLowest Pos: " << lowest << "\n" << list.getCharacter(lowest);

	cout << "\n\n";
	stringstream input;
	input << "strawberry 9";
	Item strawberry;
	cout << strawberry << "\n";
	input >> strawberry;
	cout << strawberry;


	//int x = 10;
	//int* p = &x;
	//(*p)++;
	//cout << "\n" << *p;

	return 0;
}