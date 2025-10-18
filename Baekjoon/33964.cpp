#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;

	int small = min(X, Y);
	int diff = abs(X - Y);

	string ans = "";
	for (int i = 0; i < diff; i++) {
		ans += "1";
	}

	for (int i = 0; i < small; i++) {
		ans += "2";
	}

	cout << ans << endl;

	return 0;
}