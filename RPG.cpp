#include<iostream>
#include<conio.h>
#include<string>
#include<H:\Line.h>
#include<numeric>
#include<time.h>
#include"Items.h"
#include"Move.h"

using namespace std;


int main() {
	system("cls");
	srand(time(NULL));

	//Define Weapon Types
	{
		Type Hammer("Hammer", 4, 5);
		Type Mace("Mace", 5, 4);
		Type Axe("Axe", 6, 3);
		Type Sword("Sword", 7, 2);
		Type Knife("Knife", 10, 1);
		typeList.push_back(Mace);
		typeList.push_back(Sword);
		typeList.push_back(Axe);
		typeList.push_back(Knife);
		typeList.push_back(Hammer);
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

	vector<vector<int>> level =
	{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	zone Tutorial(level);

	Weapon weapon1("Sword", -2, "Bronze");
	vector<int> damage;
	int iter = 10000;
	//for (int x = 0; x < iter; x++) {
	//	damage.push_back(weapon1.rolAtt(12));
	//}
	
	//float average = accumulate(damage.begin(), damage.end(), 0.0) / damage.size();
	//int zeroes = count(damage.begin(), damage.end(), 0);
	//cout << "The average damage was " << average << endl;
	//cout << "The hit rate was " << (1-(double(zeroes)/iter))*100 << "%" << endl;

	return 0;
}