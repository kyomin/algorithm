#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int len = str.size();
	int *DP = new int[len + 1];

	// 일단 모두 0으로 초기화!
	for (int i = 0; i <= len; i++)
		DP[i] = 0;

	DP[0] = 1;

	for (int i = 1; i <= len; i++) {
		// 숫자 문자를 정수로 바꾼다.
		int x = str[i - 1] - '0';

		if (x >= 1 && x <= 9)
			DP[i] = (DP[i] + DP[i - 1]) % 1000000;

		// 위에서 1자리 암호에 대해서 처리하였다.
		// 다음은 2자리 암호에 대해 처리하자.

		// 애초에 길이가 1이면 해당사항 x
		if (i == 1)
			continue;
		else if (str[i - 2] == '0')
			continue;

		x = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');

		if (10 <= x && x <= 26)
			DP[i] = (DP[i] + DP[i - 2]) % 1000000;
	}

	cout << DP[len] % 1000000 << '\n';

	return 0;
}