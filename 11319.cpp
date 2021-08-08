#include <iostream>
#include <string>

using namespace std;

char vowels[10] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };

bool isVowel(char ch) {
	for (int i = 0; i < 10; i++)
		if (vowels[i] == ch)
			return true;
	
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	cin.get();
	for (int t = 0; t < T; t++) {
		string sentence;
		getline(cin, sentence);

		int vowels = 0;
		int consonants = 0;
		int len = sentence.length();
		for (int i = 0; i < len; i++) {
			if (isVowel(sentence[i]))
				vowels++;
			else if(sentence[i] != ' ')
				consonants++;
		}

		cout << consonants << ' ' << vowels << '\n';
	}

	return 0;
}