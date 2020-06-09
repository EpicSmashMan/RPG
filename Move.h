#include<vector>
#include<string>

class zone {
public:
	string name;
	vector<vector<int>> level;
	zone(string name, vector<vector<int>> level);
};

zone::zone(string _name, vector<vector<int>> _level) {
	name = _name;
	level = _level;
};

vector<zone> zoneTable;

void displayZone(string zone, int x, int y) {


}

int findZone(string zone) {
	return 0;
}