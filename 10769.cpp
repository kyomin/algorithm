#include <iostream>
#include <string>

using namespace std;

string happy = ":-)";
string sad = ":-(";

int main() {
	string str;
	int happyCount = 0;
	int sadCount = 0;

	getline(cin, str);

	int len = str.size();

	for (int i = 0; i < len; i++) {
		if (str[i] == ':') {
			string temp;

			temp = str.substr(i, 3);

			if (temp == happy)
				happyCount += 1;
			else if (temp == sad)
				sadCount += 1;
		}
	}

	if (happyCount == 0 && sadCount == 0)
		cout << "none" << '\n';
	else if (happyCount == sadCount)
		cout << "unsure" << '\n';
	else if (happyCount > sadCount)
		cout << "happy" << '\n';
	else if (happyCount < sadCount)
		cout << "sad" << '\n';

	return 0;
}