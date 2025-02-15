#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool alphas[26];

int main() {
	int T;
	cin >> T;
	cin.get();	// 개행(엔터) 클리어

	for (int t = 0; t < T; t++) {
		memset(alphas, false, sizeof(alphas));

		int len;
		string result = "";
		string sentence;
		getline(cin, sentence);
		len = sentence.length();
		
		for (int i = 0; i < len; i++) {
			char ch = sentence[i];

			if (!isalpha(ch))
				continue;

			int index;
			if (islower(ch))
				index = (int)(ch - 'a');
			else
				index = (int)(ch - 'A');

			alphas[index] = true;
		}

		for (int i = 0; i < 26; i++)
			if (!alphas[i])
				result += (char)(i + 97);

		if (result == "")
			cout << "pangram" << endl;
		else
			cout << "missing " << result << endl;
	}

	return 0;
}