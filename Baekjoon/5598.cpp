#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	string answer = "";
	int len = str.size();

	for (int i = 0; i < len; i++) {
		char ch = str[i];
		ch -= 3;

		if ((int)ch < 65) {
			ch = (char)(90 - (65 - (int)ch - 1));
			answer += ch;
		}
		else
			answer += ch;
	}

	cout << answer << endl;

	return 0;
}