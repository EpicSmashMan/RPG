/*
	Item object definitions
	- Weapons (Mace, Sword, Axe, Knife, Hammer)



	Felix Wallace-Tarry DO NOT STEAL (without permission)
*/
#include<conio.h>
#include<string>
#include<vector>
#include<time.h>

using namespace std;


vector<string> typeList;

class Weapon {
	int attBonus, rolMulti, rolSize;
	int magic;
	int rolDam();
	void findType(string);
public:
	string name, type;
	int rolAtt(int);
	Weapon(string _type, int _magic);
	Weapon(int _magic) : Weapon(string "-1", int _magic);
	Weapon(string _type) : Weapon(string _type, int -1);
};

/*
Object Constructors (Weapon)
	-

*/

Weapon::Weapon(string _type, int _magic) {
	if (_magic == -1) {
		magic = (rand() / 10000) % 100;
	} else
		magic = _magic;
	if (type == "-1") {
		type = typeList[(rand() / 1000) % typeList.size()];
	} else
		findType(_type);
}


/* Object Functions */

int Weapon::rolAtt(int AC) {
	int Dam;
	if (10 + attBonus > AC)
		Dam = rolDam();
	return Dam;
}

int Weapon::rolDam() {
	int Dam = 0;
	for (int i = 0; i < rolMulti; i++)
		Dam += rand() % rolSize + 1;
	return Dam;
}

void Weapon::findType(string _type)
{
	for (int i = 0; i < typeList.size(); i++) {
		if (_type == typeList[i]) {
			this->type = typeList[i];
			break;
		}
		else if (i == typeList.size() - 1) {
			cout << "WEAPON TYPE NOT DEFINED" << endl;
			abort();
		}
	}
}
