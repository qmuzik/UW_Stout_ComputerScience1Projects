/**
	@file Ip.cpp
	@brief Creates characterf or a game

	Creates different character (personas) that have atrributes such as weapons, items, etc.

	@author Quincy Muzik
	@date 12/6/2021
*/

#include "p3.h" // Header file 

using std::string;
using std::istream;
using std::ostream;
using std::left;
using std::right;
using std::setw;
using std::stringstream;
using std::endl;
using std::cout;

Item::Item(string nItemCode, string nItemName, char nQuickKey) {

	// Assign class varibles to parameters
	itemCode = nItemCode;
	itemName = nItemName;
	quickKey = nQuickKey;

	// Checks to see if strings are empty 
	if (nItemCode == "") {
		itemCode = "JNK";
	}

	if (nItemName == "") {
		itemName = "Unknown";
	}

	// Checks to see if quick key is a letter 
	if (nQuickKey < 'A' || nQuickKey > 'Z') {
		quickKey = '\0';
	}

}

// Getters that return item values
string Item::getItemCode() const {
	return itemCode;
}

string Item::getName() const {
	return itemName;
}

char Item::getQuickKey() const {
	return quickKey;
}

void Item::updateQuickKey(char nQuickKey) {

	// Checks to see if the parameter is between A and Z or if tis \0
	if (nQuickKey >= 'A' && nQuickKey <= 'Z' || nQuickKey == '\0') {
		quickKey = nQuickKey;
	}
}

Persona::Persona(string nPersonaCode, string nPersonaId) {
	personaCode = nPersonaCode;
	personaId = nPersonaId;

	for (int i = 0; i < 5; i++) {
		itemSlots[i] = nullptr;
	}
}

Persona::Persona() {
	personaCode = "NPC";
	personaId = "unknown_0";

	for (int i = 0; i < 5; i++) {
		itemSlots[i] = nullptr;
	}
}

Persona::~Persona() {

	// Loops over the array and deletes each item 
	for (int i = 0; i < 5; i++) {
		delete itemSlots[i];
	}
}

string Persona::getPersonaCode() const {
	return personaCode;
}

string Persona::getId() const {
	return personaId;
}

const Item* Persona::getItem(int slot) const {

	// Checks to see if the item is inside the array
	if (slot < 5 && slot >= 0) {
		return itemSlots[slot];
	}

	return nullptr;
}

bool Persona::addItem(string nItemCode, string nItemName, char nQuickKey) {

	for (int i = 0; i < 5; i++) {
		if (itemSlots[i] == nullptr) {
			itemSlots[i] = new Item(nItemCode, nItemName, nQuickKey);
			return true;
		}
	}
	return false;
}

bool Persona::removeItem(int nSlot) {

	if (nSlot < 5 && nSlot >= 0) {
		if (itemSlots[nSlot] != nullptr) {
			delete itemSlots[nSlot];
			itemSlots[nSlot] = nullptr;
			return true;
		}
		return false;
	}
	return false;
}

int Persona::countItems() {

	// Number of items inside the array 
	int count = 0;

	for (int i = 0; i < 5; i++) {
		if (itemSlots[i] != nullptr) {
			count++;
		}
	}

	return count;
}

int Persona::findByKey(char fQuickKey) {

	for (int i = 0; i < 5; i++) {
		if (itemSlots[i] != nullptr) {
			if (fQuickKey == itemSlots[i]->getQuickKey()) {
				return i;
			}
		}
	}

	return -1;
}

void Persona::updateKey(char oldQuickKey, char newQuickKey) {

	for (int i = 0; i < 5; i++) {
		if (itemSlots[i] != nullptr) {
			if (oldQuickKey == itemSlots[i]->getQuickKey()) {
				itemSlots[i]->updateQuickKey(newQuickKey);
			}
		}
	}
}

Persona::Persona(const Persona& persona) {

	// Copys the persona from the parameter 
	personaCode = persona.getPersonaCode();
	personaId = persona.getId();

	// Loops over the parameters array
	for (int i = 0; i < 5; i++) {
		if (persona.itemSlots[i] != nullptr) {
			const Item* otherItem = persona.getItem(i);
			itemSlots[i] = new Item(otherItem->getItemCode(), otherItem->getName(), otherItem->getQuickKey());
		}
		else {
			itemSlots[i] = nullptr;
		}
	}
}

/**
@brief Assignment Operator

Assigns a persona object to a another persona

@param p persona that is created

*/

Persona& Persona::operator=(const Persona& p) {

	for (int i = 0; i < 5; i++) {
		delete itemSlots[i];
	}

	// Copys the persona from the parameter 
	personaCode = p.getPersonaCode();
	personaId = p.getId();

	// Loops over the parameters array
	for (int i = 0; i < 5; i++) {
		if (p.itemSlots[i] != nullptr) {
			const Item* otherItem = p.getItem(i);
			itemSlots[i] = new Item(otherItem->getItemCode(), otherItem->getName(), otherItem->getQuickKey());
		}
		else {
			itemSlots[i] = nullptr;
		}
	}

	return *this;

}

/**
	@brief Insertion operator overload

	Creates a new insertion operator overload

	@param out where the persona is being written out to
	@param p persona that is created

*/

ostream& operator<<(ostream& out, const Persona& p) {
	out << p.getId() << " " << p.getPersonaCode() << " ";
	for (int i = 0; i < 5; i++) {
		if (p.getItem(i) == nullptr) {
			out << "- - - ";
		}
		else {
			out << p.getItem(i)->getItemCode() << " " << p.getItem(i)->getName() <<
				" " << p.getItem(i)->getQuickKey() << " ";
		}
	}
	return out;
}

/**
	@brief Extraction operator overload

	Creates a new insertion operator overload

	@param in where the persona is being read from
	@param p persona that is created

*/

istream& operator>>(istream& in, Persona& p) {

	string id;
	string code;
	string itemCode;
	string itemName;
	char itemKey;

	for (int i = 0; i < 5; i++) {
		p.removeItem(i);
	}

	in >> id >> code;

	p.personaId = id;
	p.personaCode = code;

	for (int i = 0; i < 5; i++) {
		in >> itemCode >> itemName >> itemKey;
		if (itemCode != "-" && itemName != "-" && itemKey != '-') {
			p.itemSlots[i] = new Item(itemCode, itemName, itemKey);
		}
		else {
			p.itemSlots[i] = nullptr;
		}
	}

	return in;
}

PersonaList::PersonaList() {

	personaArray = new Persona[5];
	maxSize = 5;
	currentSize = 0;

}

PersonaList::~PersonaList() {
	delete[] personaArray;
}

int PersonaList::getPersonaCount() const {
	return currentSize;
}

Persona* PersonaList::getPersona(int personaPosition) {
	if (personaPosition >= 0 && personaPosition < currentSize) {
		return &personaArray[personaPosition];
	}
	else {
		return nullptr;
	}
}

const Persona* PersonaList::getPersona(int pos)const {
	if (pos >= 0 && pos < currentSize) {
		return &personaArray[pos];
	}
	else {
		return nullptr;
	}
}

void PersonaList::growArray() {

	Persona* newArray = new Persona[maxSize * 2];

	for (int i = 0; i < currentSize; i++) {
		newArray[i] = personaArray[i];
	}

	delete[] personaArray;

	personaArray = newArray;
	maxSize *= 2;
}

void PersonaList::addPersona(Persona newPersona) {

	if (currentSize == maxSize) {
		growArray();
	}

	personaArray[currentSize] = newPersona;
	currentSize++;
}

Persona* PersonaList::findPersona(string personaId) {
	for (int i = 0; i < currentSize; i++) {
		if (personaId == personaArray[i].getId()) {
			return &personaArray[i];
		}
	}
	return nullptr;
}

int PersonaList::resetKeyBindings(char quickKey) {
	bool counted = false;
	int count = 0;

	for (int i = 0; i < currentSize; i++) {
		personaArray[i].findByKey(quickKey);
		if (personaArray[i].findByKey(quickKey) != -1) {
			personaArray[i].updateKey(quickKey, '\0');
			count++;
		}
	}
	return count;
}

void PersonaList::resetList() {
	currentSize = 0;
}

PersonaUtil::PersonaUtil(PersonaList* groupPointer) {
	this->groupPointer = groupPointer;
}
PersonaList* PersonaUtil::getPersonas() {
	return groupPointer;
}

void PersonaUtil::loadPersonas(istream& in) {

	string command;

	if (groupPointer != nullptr) {
		groupPointer->resetList();

		while (in) {
			command = "";
			in >> command;
			if (command == "persona") {
				command_persona(in);
			}
			if (command == "additem") {
				command_additem(in);
			}
			if (command == "removeitem") {
				command_removeitem(in);
			}
		}
	}
}

void PersonaUtil::command_persona(istream& in) {

	Persona newPersona;

	in >> newPersona;

	groupPointer->addPersona(newPersona);
}

void PersonaUtil::command_additem(istream& in) {

	string personaId;
	string personaName;
	string personaCode;
	char quickKey;

	in >> personaId >> personaCode >> personaName >> quickKey;

	if (groupPointer->findPersona(personaId) != nullptr) {
		groupPointer->findPersona(personaId)->addItem(personaCode, personaName, quickKey);
	}
}

void PersonaUtil::command_removeitem(istream& in) {

	string personaId;
	int itemSlot;

	in >> personaId >> itemSlot;

	if (groupPointer->findPersona(personaId) != nullptr) {
		groupPointer->findPersona(personaId)->removeItem(itemSlot);
	}
}

string PersonaUtil::savePersonas() {
	stringstream list;
	string final;

	if (groupPointer == nullptr) {
		return "";
	}

	for (int i = 0; i < groupPointer->getPersonaCount(); i++) {
		list << "persona ";
		list << *groupPointer->getPersona(i) << endl;
	}

	list << "\n" << endl;
	return list.str();
}

string PersonaUtil::clearKeys(char list[], int size) {

	if (groupPointer == nullptr) {
		return "No Personas available";
	}

	stringstream report;

	report << "Keys Cleared" << endl;

	for (int i = 0; i < size; i++) {
		int numberOfPersonas = groupPointer->resetKeyBindings(list[i]);
		report << list[i] << " ";

		if (numberOfPersonas != 0) {
			report << numberOfPersonas << " " << endl;
		}
		else {
			report << "None" << endl;
		}
	}

	return report.str();
}
