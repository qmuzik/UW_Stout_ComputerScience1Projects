#pragma once
#include <string>
#include <iostream>

class Item {
	// visability?
private:
	std::string name;
	int type;

	// some private functions
public:
	// constructors
	Item(); // default constructor or a null constructor
	Item(std::string nName, int nType);
	// change data?
	// set the name
	void setName(std::string nName);
	// set the type
	void setType(int nType);
	// get data?
	// get the name
	std::string getName() const;
	// get the type
	int getType() const;
	// common operations?
	// TODO fix
	friend std::ostream& operator<<(std::ostream& out, const Item& item);
	friend std::istream& operator>>(std::istream& in, Item& item);
};



class Character {
private:
	std::string name;
	int level;
	Item* leftHand;
	Item* rightHand;

public:
	//
	Character();
	Character(std::string nName);
	Character(const Character& ch);
	~Character();

	Character& operator=(const Character& ch);


	// getters
	std::string getName() const;
	int getLevel() const;
	Item* getLeftHand() const;
	Item* getRightHand() const;
	// setters
	/**
	*
	* @param nName Name of item
	*
	*
	*/
	void setName(std::string nName);
	void setLevel(int nLevel);
	void setLeftHand(Item nLeft);
	void setRightHand(Item nRight);


	friend std::ostream& operator<<(std::ostream& out, const Character& ch);
};



class CharacterList {
private:
	Character* people;
	int count;
	int size;

	void growArray();

public:
	CharacterList();
	CharacterList(const CharacterList& list);
	// more constructors?
	~CharacterList();

	CharacterList& operator=(const CharacterList& list);

	bool addCharacter(Character ch);
	Character getCharacter(int pos) const;
	int getCount() const;
	int getLowestLevel();

	// remove character
	// find character
};