#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string s1, s2;
		cin >> s1 >> s2;

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		if (s1 == s2)
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
	}

	return 0;
}