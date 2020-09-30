#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alphabet[26];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;

	// 한 단어씩 끊어서 입력받는다.
	while (cin >> s) {	
		int len = s.size();

		for (int i = 0; i < len; i++)
			alphabet[(int)(s[i] - 'a')]++;

		s.clear();
	}

	int max = *max_element(alphabet, alphabet + 26);

	for (int i = 0; i < 26; i++)
		if (max == alphabet[i])
			cout << (char)(i + 'a');

	cout << '\n';

	return 0;
}