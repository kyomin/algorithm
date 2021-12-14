#include <iostream>
#include <string>
using namespace std;

int main() {
	bool isA = false;
	bool isB = false;
	bool isC = false;
	string str;
	cin >> str;
	int len = str.length();

	for (int i = 0; i < len; i++) {
		char ch = str[i];

		if (ch == 'A')
			isA = true;
		else if (ch == 'B')
			isB = true;
		else if (ch == 'C')
			isC = true;
	}

	if (isA) {
		for (int i = 0; i < len; i++) {
			char ch = str[i];

			if (ch == 'B' || ch == 'C' || ch == 'D' || ch == 'F')
				str[i] = 'A';
		}
	}
	else if (!isA && isB) {
		for (int i = 0; i < len; i++) {
			char ch = str[i];

			if (ch == 'C' || ch == 'D' || ch == 'F')
				str[i] = 'B';
		}
	}
	else if (!isA && !isB && isC) {
		for (int i = 0; i < len; i++) {
			char ch = str[i];

			if (ch == 'D' || ch == 'F')
				str[i] = 'C';
		}
	}
	else {
		for (int i = 0; i < len; i++)
			str[i] = 'A';
	}

	cout << str << endl;

	return 0;
}