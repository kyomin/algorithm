#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;

bool validateHiddenNumber(string numStr) {
	if (numStr.length() > 0 && numStr.length() <= 6)
		return true;

	return false;
}

int main() {
	int N;
	string str;

	cin >> N;
	cin >> str;

	ull sum = 0;
	string numStr = "";

	for (int i = 0; i < N; i++) {
		char ch = str[i];

		if (isdigit(ch)) {
			numStr += ch;

			continue;
		}

		if (validateHiddenNumber(numStr)) 
			sum  += stoull(numStr);

		numStr = "";
	}

	if (validateHiddenNumber(numStr))
		sum += stoull(numStr);

	cout << sum << endl;

	return 0;
}