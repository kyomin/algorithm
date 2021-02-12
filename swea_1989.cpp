#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		cin >> str;

		string temp = str;
		
		reverse(str.begin(), str.end());

		if (str == temp)
			cout << '#' << t << ' ' << 1 << '\n';
		else
			cout << '#' << t << ' ' << 0 << '\n';
	}

	return 0;
}