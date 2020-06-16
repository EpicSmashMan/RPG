#include<vector>
#include<string>

class zone {
public:
	string name;
	vector<vector<int>> level;
	vector<int> dimensions;
	zone(string name, vector<vector<int>> level, vector<int> dimensions);
};

zone::zone(string _name, vector<vector<int>> _level, vector<int> _dimensions) {
	name = _name;
	level = _level;
	dimensions = _dimensions;
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
	for (int i = -4; i < 5; i++) {
		for (int f = 0; f < 5; f++) {
			for (int j = -4; j < 5; j++) {
				//OUTSIDE RENDER ZONE
				if (i + y < 0 || i + y >= zoneTable[zoneNum].dimensions[0]) {
					cout << "~ ~ ~ ~ ~ ";
				}
				else if (j + x < 0 || j + x >= zoneTable[zoneNum].dimensions[1]) {
					cout << "~ ~ ~ ~ ~ ";
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
				else
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
					default:
						cout << "& & & & & ";
					}
			}
			if (i == -4) {
				if(f == 0)
					cout << "    * - Wall    ~ - Unkown";
				else if(f == 1)
					cout << "    X - Player  O - Portal";
			}
			cout << endl;
		}
	}
}

void move(char input, int &lvl, int &posX, int &posY) {
	bool invalid = false;
	system("cls");
	switch (input) {
	case 'a':
		if (zoneTable[lvl].level[posX - 1][posY] != 0)
			invalid = true;
		else
			posX--;
		break;
	case 'w':
		if (zoneTable[lvl].level[posX][posY - 1] != 0)
			invalid = true;
		else
			posY--;
		break;
	case 'd':
		if (zoneTable[lvl].level[posX + 1][posY] != 0)
			invalid = true;
		else
			posX++;
		break;
	case 's':
		if (zoneTable[lvl].level[posX][posY + 1] != 0)
			invalid = true;
		else
			posY++;
		break;
	}
	displayZone(lvl, posX, posY);
	if(invalid == true)
		cout << "Invalid Movement" << endl;
}