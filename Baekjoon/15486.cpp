#include <iostream>
#include <algorithm>

using namespace std;

// N일 까지의 최대 수익을 동적으로 담는다
int D[1500002];

// 걸리는 기간
int T[1500001];

// 금액
int P[1500001];

int N;

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];

		D[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			// 하는 경우
			D[i + T[i]] = max(D[i + T[i]], D[i] + P[i]);

			// 안 하는 경우
			D[i + 1] = max(D[i + 1], D[i]);
		}
		else if (i + T[i] > N + 1)
			// 이 경우는 항상 상담을 할 수 없는 경우이다.
			D[i + 1] = max(D[i + 1], D[i]);
	}

	cout << D[N + 1] << '\n';

	return 0;
}