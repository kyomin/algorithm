#include <iostream>
#include <string>

using namespace std;

int main() {
	while (true) {
		char alpha;
		string sentence;

		cin >> alpha;

		if (alpha == '#')
			break;

		cin.clear();
		getline(cin, sentence);

		int len = sentence.length();
		int cnt = 0;

		for (int i = 0; i < len; i++) {
			if (sentence[i] == alpha) {
				cnt++;
			}
			else {
				if (islower(alpha) && alpha == (char)(sentence[i] + 32))
					cnt++;

				if (isupper(alpha) && alpha == (char)(sentence[i] - 32))
					cnt++;
			}
		}

		cout << alpha << ' ' << cnt << endl;
	}

	return 0;
}