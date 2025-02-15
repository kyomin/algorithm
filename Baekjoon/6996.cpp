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

		if (s1.length() != s2.length()) {
			cout << s1 << " & " << s2 << " are NOT anagrams." << endl;
			continue;
		}

		string temp1 = s1;
		string temp2 = s2;

		sort(temp1.begin(), temp1.end());
		sort(temp2.begin(), temp2.end());

		if (temp1 == temp2) 
			cout << s1 << " & " << s2 << " are anagrams." << endl;
		else
			cout << s1 << " & " << s2 << " are NOT anagrams." << endl;
	}

	return 0;
}