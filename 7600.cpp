#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool alpha[26];

void solution() {
	int cnt = 0;

	for (int i = 0; i < 26; i++)
		if (alpha[i])
			cnt++;

	cout << cnt << '\n';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		memset(alpha, false, sizeof(alpha));
		string sentence;
		
		cin.clear();
		getline(cin, sentence);

		if (sentence == "#")
			break;

		int len = sentence.size();

		for (int i = 0; i < len; i++) {
			char ch = sentence[i];

			if (isalpha(ch) && isupper(ch)) {
				alpha[(int)(ch - 'A')] = true;
				continue;
			}

			if (isalpha(ch) && islower(ch)) {
				alpha[(int)(ch - 'a')] = true;
				continue;
			}
		}

		solution();
	}

	return 0;
}