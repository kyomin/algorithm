#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	// 대칭이 아닌 경우에 대한 예외처리!
	if (N == 1) {
		cout << '*' << endl;
		return 0;
	}

	for (int i = N; i >= 1; i--) {
		int num = 2 * i - 1;

		// 먼저 빈칸 출력!
		for (int j = 0; j < N - i; j++)
			cout << ' ';

		// 별 출력!
		for (int j = 0; j < num; j++)
			cout << '*';

		cout << '\n';
	}

	for (int i = 2; i <= N; i++) {
		int num = 2 * i - 1;

		for (int j = 0; j < N - i; j++)
			cout << ' ';

		for (int j = 0; j < num; j++)
			cout << '*';

		cout << '\n';
	}

	return 0;
}