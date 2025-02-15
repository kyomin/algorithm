#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	// 동적으로 배열 할당!
	int *D = new int[N + 1];

	D[1] = 0;	// 가장 작은 문제! 1일 경우 연산 횟수 0

	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + 1;

		// 2로 나눌 수 있고, 위에서 계산한 것보다 더 작은 연산 결과가 생긴다면
		if ((i % 2 == 0) && (D[i] > D[i / 2] + 1))
			D[i] = D[i / 2] + 1;

		if ((i % 3 == 0) && (D[i] > D[i / 3] + 1))
			D[i] = D[i / 3] + 1;
	}

	// for문을 다 돌면 연산 횟수 메모를 위한 배열이 다 채워졌을 것이다. 우리는 D[n]의 값이 목표이다.
	cout << D[N] << '\n';

	return 0;
}