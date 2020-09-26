#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	string temp = "";
	string result = "";
	
	bool isInTag = false;

	int len = str.size();

	for (int i = 0; i < len; i++) {
		// 여는 태그를 만났다면
		if (str[i] == '<') {
			reverse(temp.begin(), temp.end());
			result += temp;
			temp.clear();
			isInTag = true;
			temp += str[i];
			continue;
		}

		// 닫는 태그를 만났다면
		if (str[i] == '>') {
			isInTag = false;
			temp += str[i];
			result += temp;
			temp.clear();
			continue;
		}

		// 공백을 만났다면
		if (str[i] == ' ') {
			// 만일 태그 내라면
			if (isInTag) {
				temp += str[i];
				continue;
			}
			else {
				reverse(temp.begin(), temp.end());
				temp += str[i];

				result += temp;
				temp.clear();
				continue;
			}
		}

		// 그냥 문자라면
		temp += str[i];
	}

	reverse(temp.begin(), temp.end());
	result += temp;

	cout << result << '\n';

	return 0;
}