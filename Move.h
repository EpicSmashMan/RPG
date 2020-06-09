#include<vector>
#include<string>

class zone {
public:
	vector<vector<int>> level;
	zone(vector<vector<int>> level);
};

zone::zone(vector<vector<int>> _level) {
	level = _level;
};

vector<zone> zonesTable;

void displayZone(int zone, int x, int y) {
	


}