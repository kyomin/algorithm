#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string make_word(int w) {
	string make_word;

	for (int i = 0; i < w; i++) {
		make_word += 'w';
	}

	for (int i = 0; i < w; i++) {
		make_word += 'o';
	}

	for (int i = 0; i < w; i++) {
		make_word += 'l';
	}

	for (int i = 0; i < w; i++) {
		make_word += 'f';
	}

	return make_word;
}

int check_wolf_word(string word) {
	string right_word;
	int w = 0;
	int o = 0;
	int l = 0;
	int f = 0;

	// count number of w, o, l, f
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == 'w') {
			w++;
		}
		else if (word[i] == 'o') {
			o++;
		}
		else if (word[i] == 'l') {
			l++;
		}
		else if (word[i] == 'f') {
			f++;
		}
	}

	if (w != o || w != l || w != f || o != l || o != f || l != f) {
		cout << "0";
		return 0;
	}
	else {
		if (word == make_word(w)) {
			cout << "1";
			return 0;
		}
		else {
			for (int i = 1; i < w; i++) {
				right_word = make_word(w - i);
				while (word.find(right_word) != -1) {
					int size = right_word.size();
					string star;
					for (int i = 0; i < size; i++) {
						star += '*';
					}
					word.replace(word.find(right_word),
						size, star);
				}
			}

			for (int i = 0; i < word.size(); i++) {
				if (word[i] != '*') {
					cout << "0";
					return 0;
				}
			}

			cout << "1";

			return 0;
		}
	}

	return 0;
}

int main() {
	string word;

	cin >> word;
	check_wolf_word(word);

	return 0;
}