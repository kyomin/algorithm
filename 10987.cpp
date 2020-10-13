#include <iostream>
#include <string>

using namespace std;

bool vowel(char a) {
	if ((a == 'a') || (a == 'e') || (a == 'i') || (a == 'o') || (a == 'u'))
		return true;
	else
		return false;
}

int main() {
	string str;
	cin >> str;

	int len = str.size();
	int cnt = 0;

	for (int i = 0; i < len; i++)
		if (vowel(str[i]))
			cnt++;

	cout << cnt << endl;

	return 0;
}