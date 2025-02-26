#include <iostream>
#include <string>
using namespace std;

int main() {
	string document;
	string word;

	getline(cin, document);
	getline(cin, word);

	int documentLen = document.length();
	int wordLen = word.length();
	int index = 0;
	int count = 0;

	while (index < documentLen) {
		if (documentLen - index < wordLen)
			break;
		
		string subWord = document.substr(index, wordLen);

		if (word == subWord) {
			count++;

			index += wordLen;
		}
		else {
			index += 1;
		}
	}

	cout << count << endl;

	return 0;
}