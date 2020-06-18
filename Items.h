/*
	Felix Wallace-Tarry DO NOT STEAL (without permission)
*/
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

class Item {
public:
	string name;
	int amount;
	Item(string name, int amount);
};

Item::Item(string _name, int _amount) {
	name = _name;
	amount = _amount;
}

//-----------------------------------------------------------------------
//Define Weapon Materials

class Element {
public:
	string name;
	int rolSize;
	Element(string name, int rolSize);
};

Element::Element(string _name, int _rolSize) {
	name = _name;
	rolSize = _rolSize;
}

vector<Element> elmntList;

//-----------------------------------------------------------------------
//Define Weapon Types

class Type {
public:
	string name;
	int attBonus;
	int rolMulti;
	Type(string name, int attBonus, int rolMulti);
};

Type::Type(string _name, int _attBonus, int _rolMulti) {
	name = _name;
	attBonus = _attBonus;
	rolMulti = _rolMulti;
};

vector<Type> typeList;

//-----------------------------------------------------------------------
//Define Weapon Objects

class Weapon : public Item {
	int attBonus, rolMulti, rolSize;
	int rolDam();
	void randomize();
	void findType(string);
	void findElmnt(string);
public:
	string type, elmnt;
	int magic, durab;
	int rolAtt(int);
	Weapon(string _type, int _magic, string _elmnt);
	Weapon(int _magic) : Weapon("-1", _magic, "-1") {};
	Weapon(string _type) : Weapon(_type, -1, "-1") {};
	Weapon(string _type, string _elmnt) : Weapon(_type, -1, _elmnt) {};
	Weapon(void) : Weapon("-1", -1, "-1") {};
};

Weapon::Weapon(string _type, int _magic, string _elmnt) : Item(_type, 1) {
	randomize();
	if (_magic == -1) {
		if (rand() % 2 == 1) {
			magic = rand() % 100;
		}
		else
			magic = -2;
	}
	else
		magic = _magic;
	if (_type == "-1") {
		int ran = rand() % typeList.size();
		type = typeList[ran].name;
		attBonus = typeList[ran].attBonus;
		rolMulti = typeList[ran].rolMulti;
	}
	else
		findType(_type);
	if (_elmnt == "-1") {
		int ran = rand() % elmntList.size();
		elmnt = elmntList[ran].name;
		rolSize = elmntList[ran].rolSize;
	}
	else
		findElmnt(_elmnt);

}

/* Weapon Functions */

void Weapon::randomize() {
	static bool seeded = false;
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
}

int Weapon::rolAtt(int AC) {
	int Dam;
	int x = rand() % 20;
	cout << "You attacked with a roll of " << x + attBonus << " (" << x << ")" << endl;
	if (x + attBonus > AC)
		Dam = rolDam();
	else
		Dam = 0;
	cout << "You did " << Dam << " Damage" << endl;
	return Dam;
}

int Weapon::rolDam() {
	int Dam = 0;
	for (int i = 0; i < rolMulti; i++) {
		Dam += (rand() % rolSize) + 1;
	}
	return Dam;
}

void Weapon::findType(string _type)
{
	for (int i = 0; i < typeList.size(); i++) {
		if (_type == typeList[i].name) {
			type = typeList[i].name;
			attBonus = typeList[i].attBonus;
			rolMulti = typeList[i].rolMulti;
			break;
		}
		if (i == typeList.size() - 1) {
			cout << "WEAPON TYPE NOT DEFINED" << endl;
			abort();
		}
	}
}

void Weapon::findElmnt(string _elmnt)
{
	for (int i = 0; i < typeList.size(); i++) {
		if (_elmnt == elmntList[i].name) {
			elmnt = elmntList[i].name;
			rolSize = elmntList[i].rolSize;
			break;
		}
		if (i == elmntList.size() - 1) {
			cout << "MATERIAL TYPE NOT DEFINED" << endl;
			abort();
		}
	}
}


vector<Item*> Inventory;