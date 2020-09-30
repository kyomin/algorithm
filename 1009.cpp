#include <iostream>

using namespace std;

int solution(int a, int b) {
	int result = a;

	// 1의 자리만 고려한다.
	for (int i = 2; i <= b; i++)
		result = (result*a) % 10;

	// 최종 1의 자리가 0이면 10번째 컴퓨터인 경우이다.
	if (result == 0)
		result = 10;

	// 그 외에는 일의 자리에 매칭되는 컴퓨터이다.
	return result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int a, b;
		cin >> a >> b;

		cout << solution(a, b) << '\n';
	}

	return 0;
}