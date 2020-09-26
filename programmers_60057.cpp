#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = 1000;

	int len = s.size();
	int boundary = len / 2;
	int l = 1;

	while (l <= boundary) {
		string currentStr;
		string compressionStr = "";
		int cnt = 1;

		for (int i = 0; i < len; i += l) {
			if (i == 0) {
				currentStr = s.substr(i, l);
				continue;
			}

			if (s.substr(i, l) == currentStr) {
				cnt++;
			}
			else {
				if (cnt == 1) {
					compressionStr += currentStr;
				}
				else {
					compressionStr = compressionStr + to_string(cnt) + currentStr;
				}

				currentStr = s.substr(i, l);
				cnt = 1;
			}
		}

		if (cnt == 1) {
			compressionStr += currentStr;
		}
		else {
			compressionStr = compressionStr + to_string(cnt) + currentStr;
		}

		if (answer > compressionStr.size())
			answer = compressionStr.size();
		
		l++;
	}

	return answer;
}

int main() {
	cout << solution("aabbaccc") << '\n';
	cout << solution("ababcdcdababcdcd") << '\n';
	cout << solution("abcabcdede") << '\n';
	cout << solution("abcabcabcabcdededededede") << '\n';
	cout << solution("xababcdcdababcdcd") << '\n';
	cout << solution("aaaaaa") << '\n';

	return 0;
}