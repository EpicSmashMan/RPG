#include<vector>
#include<string>

class inter {
public:
	string name;
	vector<int> position;
	vector<Item*> contains;
	inter(string name, vector<int> position, vector<Item*> contains);
};

inter::inter(string _name, vector<int> _position, vector<Item*> _contains) {
	name = _name;
	position = _position;
	contains = _contains;
}

class zone {
public:
	string name;
	vector<vector<int>> level;
	vector<int> dimensions;
	vector<inter> inters;
	zone(string name, vector<vector<int>> level, vector<int> dimensions, vector<inter> inters);
};

zone::zone(string _name, vector<vector<int>> _level, vector<int> _dimensions, vector<inter> _inters) {
	name = _name;
	level = _level;
	dimensions = _dimensions;
	inters = _inters;
};

vector<zone> zoneTable;

int findZone(string _name) {
	for (int i = 0; i < zoneTable.size(); i++) {
		if (_name == zoneTable[i].name) {
			return i;
			break;
		}
		if (i == zoneTable.size() - 1) {
			cout << "LEVEL NOT DEFINED" << endl;
			abort();
		}
	}
}

void displayZone(int zoneNum, int x, int y) {
	for (int i = -5; i < 5; i++) {
		for (int f = 0; f < 5; f++) {
			bool filled = false;
			for (int j = -6; j < 7; j++) {
				//OUTSIDE RENDER ZONE
				if (j + x >= zoneTable[zoneNum].dimensions[0] || i + y >= zoneTable[zoneNum].dimensions[1]) {}
				else if (i + y < 0) {
					filled = true;
				}
				else if (j + x < 0) {
					cout << "          ";
				}
				//RENDER PLAYER
				else if (i + y == y && j + x == x) {
					switch (f) {
					case 0:
						cout << "    _     ";
						break;
					case 1:
						cout << "   |_|    ";
						break;
					case 2:
						cout << "   /|\\    ";
						break;
					case 3:
						cout << "    |     ";
						break;
					case 4:
						cout << "   / \\    ";
					}
				}
				//RENDER BLOCKS
				else {
					switch (zoneTable[zoneNum].level[i + y][j + x]) {
					case 0:
						cout << "          ";
						break;
					case 1:
						switch (f) {
						case 0:
							cout << "----------";
							break;
						case 1:
							cout << "          ";
							break;
						case 2:
							cout << "----------";
							break;
						case 3:
							cout << "          ";
							break;
						case 4:
							cout << "----------";
						}
						break;
					case 2:
						switch (f) {
						case 0:
							cout << "|   |   | ";
							break;
						case 1:
							cout << "|   |   | ";
							break;
						case 2:
							cout << "|   |   | ";
							break;
						case 3:
							cout << "|   |   | ";
							break;
						case 4:
							cout << "|   |   | ";
						}
						break;
					case 3:
						switch (f) {
						case 0:
							cout << "----------";
							break;
						case 1:
							cout << "|         ";
							break;
						case 2:
							cout << "|   ------";
							break;
						case 3:
							cout << "|   |     ";
							break;
						case 4:
							cout << "|   |   --";
						}
						break;
					case 4:
						switch (f) {
						case 0:
							cout << "--------- ";
							break;
						case 1:
							cout << "        | ";
							break;
						case 2:
							cout << "------  | ";
							break;
						case 3:
							cout << "    |   | ";
							break;
						case 4:
							cout << "--  |   | ";
						}
						break;
					case 5:
						switch (f) {
						case 0:
							cout << "|   |   --";
							break;
						case 1:
							cout << "|   |     ";
							break;
						case 2:
							cout << "|   ------";
							break;
						case 3:
							cout << "|         ";
							break;
						case 4:
							cout << "----------";
						}
						break;
					case 6:
						switch (f) {
						case 0:
							cout << "--  |   | ";
							break;
						case 1:
							cout << "    |   | ";
							break;
						case 2:
							cout << "------  | ";
							break;
						case 3:
							cout << "        | ";
							break;
						case 4:
							cout << "--------- ";
						}
						break;
					case 7:
						switch (f) {
						case 0:
							cout << "  ------  ";
							break;
						case 1:
							cout << " |      | ";
							break;
						case 2:
							cout << " |      | ";
							break;
						case 3:
							cout << " |      | ";
							break;
						case 4:
							cout << "  ------  ";
						}
						break;
					case 8:
						switch (f) {
						case 0:
							cout << "          ";
							break;
						case 1:
							cout << "  ______  ";
							break;
						case 2:
							cout << " |  __  | ";
							break;
						case 3:
							cout << " |------| ";
							break;
						case 4:
							cout << " |______| ";
						}
						break;
					case 9:
						switch (f) {
						case 0:
							cout << "  ______  ";
							break;
						case 1:
							cout << " |__==__| ";
							break;
						case 2:
							cout << " |------| ";
							break;
						case 3:
							cout << " |______| ";
							break;
						case 4:
							cout << " |______| ";
						}
						break;
					case 10:
						switch (f) {
						case 0:
							cout << "   ----   ";
							break;
						case 1:
							cout << "  |    |  ";
							break;
						case 2:
							cout << "  |*   |  ";
							break;
						case 3:
							cout << "  |    |  ";
							break;
						case 4:
							cout << "   ----   ";
						}
						break;
					default:
						cout << "& & & & & ";
					}
					filled = true;
				}
			}
			if(filled == true)
				cout << endl;
		}
	}
}

void move(char input, string &level, int &posX, int &posY) {
	bool invalid = false;
	int lvl = findZone(level);
	system("cls");
	switch (input) {
	case 'a':
		if (zoneTable[lvl].level[posY][posX - 1] != 0 && zoneTable[lvl].level[posY][posX - 1] < 8)
			invalid = true;
		else
			posX--;
		break;
	case 'w':
		if (zoneTable[lvl].level[posY - 1][posX] != 0 && zoneTable[lvl].level[posY - 1][posX] < 8)
			invalid = true;
		else
			posY--;
		break;
	case 'd':
		if (zoneTable[lvl].level[posY][posX + 1] != 0 && zoneTable[lvl].level[posY][posX + 1] < 8)
			invalid = true;
		else
			posX++;
		break;
	case 's':
		if (zoneTable[lvl].level[posY + 1][posX] != 0 && zoneTable[lvl].level[posY + 1][posX] < 8)
			invalid = true;
		else
			posY++;
		break;
	}
	displayZone(lvl, posX, posY);
	if(invalid == true)
		cout << "Invalid Movement" << endl;
	else if (zoneTable[lvl].level[posY][posX] == 8) {
		cout << "You found a chest!" << endl;
		cout << "Open it? (Y/N)" << endl;
		char action = _getch();
		switch (action) {
		case 'n':
		case 'N':
			cout << "You decide to leave it closed" << endl;
			break;
		case 'y':
		case 'Y':
			for (int i = 0; i < zoneTable[lvl].inters.size(); i++) {
				if (zoneTable[lvl].inters[i].position[0] == posX && zoneTable[lvl].inters[i].position[1] == posY) {
					for (int j = 0; j < zoneTable[lvl].inters[i].contains.size(); j++) {
						cout << "You got " << zoneTable[lvl].inters[i].contains[j]->name << " x" << zoneTable[lvl].inters[i].contains[j]->amount << endl;
						Inventory.push_back(zoneTable[lvl].inters[i].contains[j]);
					}
					zoneTable[lvl].inters[i].contains.erase(zoneTable[lvl].inters[i].contains.begin(), zoneTable[lvl].inters[i].contains.end());
					zoneTable[lvl].level[posY][posX] = 9;
				}
			}
		}
	}
	else if (zoneTable[lvl].level[posY][posX] == 10) {
		for (int i = 0; i < zoneTable[lvl].inters.size(); i++) {
			if (zoneTable[lvl].inters[i].position[0] == posX && zoneTable[lvl].inters[i].position[1] == posY) {
				level = zoneTable[lvl].inters[i].contains[0]->name;
			}
		}
	}
}