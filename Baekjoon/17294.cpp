#include <iostream>
#include <string>
using namespace std;

const string cute = "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
const string notCute = "흥칫뿡!! <(￣ ﹌ ￣)>";

int main() {
	string sequence;
	cin >> sequence;

	int len = sequence.length();
	if (len == 1) {
		cout << cute << endl;
		return 0;
	}

	int a0 = (int)(sequence[0] - '0');
	int a1 = (int)(sequence[1] - '0');
	int d = a1 - a0;

	bool flag = true;

	for (int i = 2; i < len; i++) {
		int before = (int)(sequence[i - 1] - '0');
		int cur = (int)(sequence[i] - '0');

		if (before + d != cur) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << cute << endl;
	else
		cout << notCute << endl;

	return 0;
}