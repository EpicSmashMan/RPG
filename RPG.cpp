#include<iostream>
#include<conio.h>
#include<string>
#include<numeric>
#include<time.h>
#include"Items.h"
#include"Move.h"

using namespace std;


int main() {
	system("cls");
	srand(time(NULL));
	int posX, posY;
	string level;

	posX = 6; posY = 5;
	level = "Tutorial";






	//Define Weapon Types
	{
		Type Hammer("Hammer", 4, 5);
		Type Mace("Mace", 5, 4);
		Type Axe("Axe", 6, 3);
		Type Sword("Sword", 7, 2);
		Type Knife("Knife", 10, 1);
		Type Short_Sword("Short Sword", 6, 3);
		typeList.push_back(Mace);
		typeList.push_back(Sword);
		typeList.push_back(Axe);
		typeList.push_back(Knife);
		typeList.push_back(Hammer);
		typeList.push_back(Short_Sword);
	}

	//Define Weapon Materials
	{
	Element Bronze("Bronze", 4);
	Element Iron("Iron", 6);
	Element Steel("Steel", 8);
	Element Mythril("Mythril", 10);
	Element Adamantium("Adamantium", 12);
	elmntList.push_back(Bronze);
	elmntList.push_back(Iron);
	elmntList.push_back(Steel);
	elmntList.push_back(Mythril);
	elmntList.push_back(Adamantium);
	}

	//Define Levels
	{
		/* 
		0 - empty space
		1 - horizontal wall
		2 - vertical wall
		3 - Top left corner
		4 - Top right corner
		5 - bottom left corner
		6 - bottom right corner
		7 - pillar
		*/
		vector<vector<int>> level =
		{
		{3,1,1,1,1,1,1,1,1,4},
		{2,0,0,0,0,0,0,0,0,2},
		{2,0,7,0,0,0,0,7,0,2},
		{2,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,2},
		{2,0,7,0,0,0,0,7,0,2},
		{2,0,0,0,0,0,0,0,0,2},
		{5,1,1,1,1,1,1,1,1,6},
		};
		vector<int> dimensions = { 10, 10 };
		zone Tutorial("Tutorial", level, dimensions);
		zoneTable.push_back(Tutorial);
	}
	int lvl = findZone(level);

	char action;
	displayZone(lvl, posX, posY);


	while (1 == 1) {
		action = _getch();
		if (action == 'a' || 'd' || 's' || 'w') {
			move(action, lvl, posX, posY);
		}
		else
			cout << "else" << endl;
	}

	//vector<int> damage;
	//int iter = 10000;
	//for (int x = 0; x < iter; x++) {
	//	damage.push_back(weapon1.rolAtt(12));
	//}
	
	//float average = accumulate(damage.begin(), damage.end(), 0.0) / damage.size();
	//int zeroes = count(damage.begin(), damage.end(), 0);
	//cout << "The average damage was " << average << endl;
	//cout << "The hit rate was " << (1-(double(zeroes)/iter))*100 << "%" << endl;

	return 0;
}