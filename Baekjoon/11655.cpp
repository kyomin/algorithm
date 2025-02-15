#include <iostream>
#include <string>
#include <cctype> // isupper를 위해서

using namespace std;

int main() {
	string result = "";	// 결과 문자열을 담기 위한 변수
	string str;
	getline(cin, str);

	int len = str.size();

	for (int i = 0; i < len; i++) {
		// 대문자의 경우!
		if (isupper(str[i])) {
			// 아스키 정수 값을 담는다.
			int temp = (int)str[i];

			// 13만큼 밀어낸다.
			temp += 13;

			// 'Z'를 넘어가면
			if (temp > 90) {
				// 아스키 값(정수)연산한 것을 다시 문자화 한다.
				char c = char((temp % 91) + 65);
				result += c;
			}
			else
				result += (char)temp;
		}
		// 소문자의 경우
		else if (islower(str[i])) {
			// 아스키 정수 값을 담는다.
			int temp = (int)str[i];

			// 13만큼 밀어낸다.
			temp += 13;

			// 'Z'를 넘어가면
			if (temp > 122) {
				char c = char((temp % 123) + 97);
				result += c;
			}
			else
				result += (char)temp;
		}
		// 공백을 만난다면
		else
			result += str[i];
	}

	cout << result << endl;

	return 0;
}