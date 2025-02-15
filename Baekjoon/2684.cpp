#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int frequencies[8];

int getIndex(string str) {
	int ret;

	if (str == "TTT")
		ret = 0;
	else if (str == "TTH")
		ret = 1;
	else if (str == "THT")
		ret = 2;
	else if (str == "THH")
		ret = 3;
	else if (str == "HTT")
		ret = 4;
	else if (str == "HTH")
		ret = 5;
	else if (str == "HHT")
		ret = 6;
	else if (str == "HHH")
		ret = 7;

	return ret;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		memset(frequencies, 0, sizeof(frequencies));
		string coins;
		cin >> coins;

		for (int start = 0; start <= 37; start++) {
			string sequence = coins.substr(start, 3);
			int index = getIndex(sequence);
			frequencies[index]++;
		}

		for (int i = 0; i < 7; i++)
			cout << frequencies[i] << ' ';

		cout << frequencies[7] << endl;
	}

	return 0;
}