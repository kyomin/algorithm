#include <iostream>

using namespace std;

int main() {
	int N, a, b;
	cin >> N >> a >> b;

	// 라운드는 1부터 시작!
	int round = 1;

	while (N != 1) {
		// 서로 대결을 하는 라운드면 탈출!
		if ((a + 1) / 2 == (b + 1) / 2)
			break;
		// 참가자의 수가 홀수일 경우.
		else if (N % 2 == 1) {
			a = (a + 1) / 2;
			b = (b + 1) / 2;
			N = (N / 2) + 1;
			round++;
		}
		else {
			a = (a + 1) / 2;
			b = (b + 1) / 2;
			N = (N / 2);
			round++;
		}
	}

	if (N == 1)
		cout << -1 << endl;
	else
		cout << round << endl;

	return 0;
}