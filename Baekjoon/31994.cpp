#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> seminar;

	for (int i = 0; i < 7; i++) {
		string key; 
		int value;
		cin >> key >> value;

		seminar[key] = value;
	}

	string maxKey;
	int maxValue = -1;

	for (const auto& pair : seminar) {
		if (pair.second > maxValue) {
			maxValue = pair.second;
			maxKey = pair.first;
		}
	}

	cout << maxKey << endl;

	return 0;
}