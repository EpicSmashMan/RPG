#include<iostream>
#include<conio.h>
#include<string>
#include<H:\Line.h>
#include<time.h>
#include"Items.h"

using namespace std;



int main() {
	system("cls");
	srand(time(NULL));
	typeList.push_back("Mace");
	typeList.push_back("Sword");
	typeList.push_back("Axe");
	typeList.push_back("Knife");
	typeList.push_back("Hammer");

	Weapon weapon1("Knife");
	cout << weapon1.type << endl;
	return 0;
}