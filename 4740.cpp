#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		string str;
		getline(cin, str);

		if (str == "***")
			break;

		reverse(str.begin(), str.end());

		cout << str << endl;
	}

	return 0;
}