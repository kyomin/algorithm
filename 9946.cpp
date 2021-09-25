#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t = 1;
	while (true) {
		string s1, s2;
		cin >> s1 >> s2;

		if ((s1 == "END") && (s2 == "END"))
			break;

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		if (s1 == s2)
			cout << "Case " << t++ << ": same" << endl;
		else
			cout << "Case " << t++ << ": different" << endl;
	}

	return 0;
}