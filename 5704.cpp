#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool alpha[26];

int main() {
	while (true) {
		memset(alpha, false, sizeof(alpha));
		string sentence;
		getline(cin, sentence);

		if (sentence == "*")
			break;

		int len = sentence.length();

		for (int i = 0; i < len; i++) {
			int idx = (int)(sentence[i] - 'a');
			alpha[idx] = true;
		}

		bool flag = true;

		for (int i = 0; i < 26; i++) {
			if (!alpha[i]) {
				flag = false;
				break;
			}
		}

		if (flag)
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
	}

	return 0;
}