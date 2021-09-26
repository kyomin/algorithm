#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	cin.get();

	for (int t = 0; t < T; t++) {
		string text;
		getline(cin, text);

		int len = text.length();
		for (int i = 0; i < len; i++) {
			char ch = text[i];

			if (isalpha(ch) && isupper(ch))
				text[i] = (char)(ch + 32);
		}

		string temp = text;
		reverse(text.begin(), text.end());

		if (temp == text)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}