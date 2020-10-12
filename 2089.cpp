#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long N;
	cin >> N;

	string s = "";

	// 0 입력에 대한 예외처리!
	if (N == 0) {
		cout << N << endl;
		return 0;
	}

	// 계속 나누는 과정에서 1이 아닐 때까지!
	while (N != 1) {
		/*
			양수와 음수의 경우를 나누자.
		*/

		// 양수인 경우에는
		if (N > 0) {
			// 나머지는 곧 2로 나눈 나머지와 같을 것이고,
			long long r = N % 2;

			// 몫은 -2로 나눴을 때의 몫과 같다. 여기서 몫은 음수로 나올 것이다.
			N /= (-2);

			// 결과 문자열에 나머지 부분 더해준다.
			s += (char)('0' + r);
		}
		// 음수인 경우에는
		else if (N < 0) {
			// 만일 절댓값이 2로 나누어 떨어진다면
			if (abs(N) % 2 == 0) {
				// 그대로 -2로 나눈 몫을 취하고
				N /= (-2);

				// 이 경우에는 나머지가 어차피 0이므로 문자열에 더한다.
				s += '0';

			}
			// 절댓값이 2로 나누어 떨어지지 않는다면
			else if (abs(N) % 2 == 1) {
				// 1 더 큰 값으로 몫을 취해야 하는 경우이다.
				N = abs(N) / 2 + 1;

				// 이 경우에는 어차피 나머지가 1이므로 문자열에 더한다.
				s += '1';
			}
		}
	}

	// N이 1이 되어 while문을 빠져나온다면 최종 결과 문자열에 1 더해주기!
	s += '1';

	// 거꾸로 더한 셈이므로 뒤집는다.
	reverse(s.begin(), s.end());

	// 그리고 결과 출력!
	cout << s << '\n';

	return 0;
}