#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string command;
		cin >> command;
		int len = command.length();

		if (len != 7) {
			cout << 0 << endl;
			continue;
		}

		if (command[0] == command[1] &&
			command[0] == command[4] &&
			command[6] == command[2] &&
			command[6] == command[3] &&
			command[6] == command[5] &&
			command[0] != command[6]) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}