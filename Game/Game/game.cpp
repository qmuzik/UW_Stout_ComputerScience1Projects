#include "game.h"

using namespace std;

Item::Item() {
	name = "Steve";
	type = 42;
}

Item::Item(std::string nName, int nType) {
	if (nName != "") {
		name = nName;
	}
	else {
		name = "Steve";
	}
	type = nType;
}


// set the name
void Item::setName(std::string nName) {
	if (nName != "") {
		name = nName;
	}
}
// set the type
void Item::setType(int nType) {
	type = nType;
}
// get data?
// get the name
std::string Item::getName() const {
	return name;
}
// get the type
int Item::getType() const {
	return type;
}



Character::Character() {
	name = "No Idea";
	level = 4;
	// hands
	leftHand = nullptr;
	rightHand = nullptr;
}

Character::Character(std::string nName) {
	name = nName;
	level = 4;
	// hands
	leftHand = nullptr;
	rightHand = nullptr;
}

Character::Character(const Character& ch) {
	name = ch.getName();
	level = ch.level;
	if (ch.leftHand != nullptr) {
		leftHand = new Item(ch.leftHand->getName(), ch.leftHand->getType());
	}
	else {
		leftHand = nullptr;
	}
	if (ch.rightHand != nullptr) {
		rightHand = new Item(*ch.rightHand);
	}
	else {
		rightHand = nullptr;
	}
}

Character::~Character() {
	//release memory
	delete leftHand;
	delete rightHand;
}

Character& Character::operator=(const Character& ch) {

	// check if same
	// a = a;
	if (this == &ch) {
		return *this;
	}

	// destroy the dynamic data (destructor)
	delete leftHand;
	delete rightHand;
	// copy everything over (copy constructor)
	name = ch.getName();
	level = ch.level;
	if (ch.leftHand != nullptr) {
		leftHand = new Item(ch.leftHand->getName(), ch.leftHand->getType());
	}
	else {
		leftHand = nullptr;
	}
	if (ch.rightHand != nullptr) {
		rightHand = new Item(*ch.rightHand);
	}
	else {
		rightHand = nullptr;
	}
	// return myself
	return *this;
}



std::string Character::getName()  const {
	return name;
}

int Character::getLevel() const {
	return level;
}
Item* Character::getLeftHand() const {
	return leftHand;
}
Item* Character::getRightHand() const {
	return rightHand;
}

// setters
void Character::setName(std::string nName) {
	name = nName;
}

void Character::setLevel(int nLevel) {
	level = nLevel;
}

void Character::setLeftHand(Item nLeft) {
	delete leftHand;
	leftHand = new Item;
	leftHand->setName(nLeft.getName());
	leftHand->setType(nLeft.getType());
}

void Character::setRightHand(Item nRight) {
	delete rightHand;
	rightHand = new Item(nRight.getName(), nRight.getType());
}




std::ostream& operator<<(std::ostream& out, const Item& item) {
	out << item.getName() << " " << item.type;

	return out;
}

std::istream& operator>>(std::istream& in, Item& item) {
	// add error checking
	// assume that name has no spaces
	string itemName;
	in >> itemName;
	//item.setName(itemName);
	item.name = itemName;

	in >> item.type;

	return in;
}


std::ostream& operator<<(std::ostream& out, const Character& ch) {
	out << ch.getName() << " Level: " << ch.getLevel();
	if (ch.getLeftHand() != nullptr) {
		out << "\n\tLeft: " << (*ch.getLeftHand()).getName();
	}
	else {
		out << "\n\tLeft: Empty";
	}
	if (ch.getRightHand() != nullptr) {
		out << "\n\tRight: " << ch.getRightHand()->getName();
	}
	else {
		out << "\n\tRight: Empty";
	}

	return out;
}





CharacterList::CharacterList() {
	people = new Character[5];
	count = 0;
	size = 5;
}

CharacterList::CharacterList(const CharacterList& list) {
	people = new Character[list.size];
	count = list.count;
	size = list.size;

	for (int i = 0; i < count; i++) {
		people[i] = list.people[i];
	}
}

// more constructors?
CharacterList::~CharacterList() {
	delete[] people;
}

CharacterList& CharacterList::operator=(const CharacterList& list) {

	if (this == &list) {
		return *this;
	}

	delete[] people;

	people = new Character[list.size];
	count = list.count;
	size = list.size;

	for (int i = 0; i < count; i++) {
		people[i] = list.people[i];
	}

	return *this;
}



void CharacterList::growArray() {
	// create a new, bigger array
	Character* newData = new Character[size + 7];

	// copy the old data into the new array
	for (int i = 0; i < size; i++) {
		newData[i] = people[i];
	}

	// point to the new array
	delete[] people;
	people = newData;

	// inc. size
	size += 7;
}


bool CharacterList::addCharacter(Character ch) {
	// check if the array is full

	if (count == size) {
		// grow the array
		growArray();
	}

	// add character to the array
	people[count] = ch;
	// inc count
	count++;
	return true;
}

Character CharacterList::getCharacter(int pos) const {
	if (pos >= 0 && pos < count) {
		return people[pos];
	}

	// create a dummy value
	Character dummy;
	return dummy;

}

int CharacterList::getCount() const {
	return count;
}


int CharacterList::getLowestLevel() {
	//int lowestLevel;
	int lowestPos;

	if (count == 0) {
		return -1;
	}

	// setup
	lowestPos = 0;
	// lowestLevel = people[0].getLevel();

	for (int i = 0; i < count; i++) {
		// check if lowest
		// (people[i].getLevel() < lowestLevel) {
		if (people[i].getLevel() < people[lowestPos].getLevel()) {
			// update lowest
			lowestPos = i;
			// lowestLevel = people[lowestPos].getLevel();
		}
	}

	return lowestPos;
}

