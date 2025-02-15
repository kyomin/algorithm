#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string result = "";
	string str1, str2;
	cin >> str1 >> str2;

	// 캐리를 위한 변수!
	int carry = 0;
	int len1 = str1.size();
	int len2 = str2.size();

	if (len1 > len2) {
		// 문자열 길이의 차이를 구한다.
		int dif = len1 - len2;

		for (int i = len2 - 1; i >= 0; i--) {
			int n1 = (int)(str1[i + dif] - '0');
			int n2 = (int)(str2[i] - '0');

			if ((n1 + n2 + carry) == 0) {
				result += '0';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 1) {
				result += '1';
				carry = 0;
			}
			// 여기서부터 캐리가 생기는 지점이다.
			else if ((n1 + n2 + carry) == 2) {
				result += '0';
				carry = 1;
			} 
			else if ((n1 + n2 + carry) == 3) {
				result += '1';
				carry = 1;
			}
		}

		// 긴 쪽의 남아있는 부분을 처리한다.
		string remains = str1.substr(0, dif);

		for (int i = dif - 1; i >= 0; i--) {
			int n = (int)(remains[i] - '0');

			if (n + carry == 0) {
				result += '0';
				carry = 0;
			}
			else if (n + carry == 1) {
				result += '1';
				carry = 0;
			}
			else if (n + carry == 2) {
				result += '0';
				carry = 1;
			}
		}

		// 작업을 다 마쳤는데도 캐리가 하나 있다면
		if (carry == 1)
			result += '1';
	}
	else if (len1 < len2) {
		int dif = len2 - len1;

		for (int i = len1 - 1; i >= 0; i--) {
			int n1 = (int)(str2[i + dif] - '0');
			int n2 = (int)(str1[i] - '0');

			if ((n1 + n2 + carry) == 0) {
				result += '0';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 1) {
				result += '1';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 2) {
				result += '0';
				carry = 1;
			}
			else if ((n1 + n2 + carry) == 3) {
				result += '1';
				carry = 1;
			}
		}

		string remains = str2.substr(0, dif);

		for (int i = dif - 1; i >= 0; i--) {
			int n = (int)(remains[i] - '0');

			if (n + carry == 0) {
				result += '0';
				carry = 0;
			}
			else if (n + carry == 1) {
				result += '1';
				carry = 0;
			}
			else if (n + carry == 2) {
				result += '0';
				carry = 1;
			}
		}

		// 작업을 다 마쳤는데도 캐리가 하나 있다면
		if (carry == 1)
			result += '1';
	}
	else {
		for (int i = len1 - 1; i >= 0; i--) {
			int n1 = (int)(str2[i] - '0');
			int n2 = (int)(str1[i] - '0');

			if ((n1 + n2 + carry) == 0) {
				result += '0';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 1) {
				result += '1';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 2) {
				result += '0';
				carry = 1;
			}
			else if ((n1 + n2 + carry) == 3) {
				result += '1';
				carry = 1;
			}
		}

		if (carry == 1)
			result += '1';
	}

	// 뒤에서부터 더한 셈이므로 뒤집어줘야 제대로 된 결과가 나온다.
	reverse(result.begin(), result.end());

	// result 문자열에 1이 나오는지의 판단용 변수
	int judge = 0;
	int length = result.size();

	// 최종 답을 담기 위한 변수이다.
	string final;

	// result 앞에 0이 붙어있으면 그것을 제거하는 과정이다.
	for (int i = 0; i < length; i++) {
		// 1을 만나는 순간
		if (result[i] == '1') {
			// 그 지점부터 끝까지 문자열을 잘라낸다.
			final = result.substr(i, length);
			// 판단용 변수를 하나 증가시킨다.
			judge++;

			// 반복문 탈출!
			break;
		}
	}

	// 만일 위의 반복문을 다 돌았는데도 judge가 0이라면 결과가 곧 0이란 소리이므로
	if (judge == 0)
		final = "0";

	cout << final << endl;

	return 0;
}