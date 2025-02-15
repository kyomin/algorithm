#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	
	return false;
}

int main() {
	string str;
	getline(cin, str);

	int len = str.length();
	int idx = 0;
	string ans = "";

	while (idx < len) {
		char ch = str[idx];
		ans += ch;

		if (!isVowel(ch))
			idx++;
		else
			idx += 3;
	}

	cout << ans << endl;

	return 0;
}