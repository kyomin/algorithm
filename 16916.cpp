#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.size();
	int len2 = s2.size();

	bool judge = false;

	for (int i = 0; i <= len1 - len2; i++) {
		if (s2 == s1.substr(i, len2))
			judge = true;
	}

	if (judge)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}