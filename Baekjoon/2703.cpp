#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	cin.get();

	for (int t = 0; t < T; t++) {
		string sentence;
		string alphas;
		string result = "";

		getline(cin, sentence);
		cin >> alphas;
		cin.get();

		int len = sentence.length();
		for (int i = 0; i < len; i++) {
			char ch = sentence[i];

			if (ch == ' ') {
				result += ch;
				continue;
			}

			int index = (int)(ch - 'A');
			result += alphas[index];
		}

		cout << result << endl;
	}

	return 0;
}