#include <string>
#include <vector>
using namespace std;

char alphas[26] = { 
	'a',
	'b',
	'c',
	'd',
	'e',
	'f',
	'g',
	'h',
	'i',
	'j',
	'k',
	'l',
	'm',
	'n',
	'o',
	'p',
	'q',
	'r',
	's',
	't',
	'u',
	'v',
	'w',
	'x',
	'y',
	'z'
};

bool isSkiped(char alpha, string skip) {
	int len = skip.length();

	for (int i = 0; i < len; i++)
		if (skip[i] == alpha)
			return true;

	return false;
}

int getIndex(char alpha) {
	for (int i = 0; i < 26; i++)
		if (alphas[i] == alpha)
			return i;
}

string solution(string s, string skip, int index) {
	string answer = "";
	int len = s.length();

	for (int i = 0; i < len; i++) {
		char alpha = s[i];
		int cnt = 1;
		int curIndex = getIndex(alpha);

		while (cnt <= index) {
			curIndex++;

			if (curIndex == 26)
				curIndex = 0;

			if (isSkiped(alphas[curIndex], skip))
				continue;

			cnt++;
		}

		answer += alphas[curIndex];
	}

	return answer;
}