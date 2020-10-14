#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	unsigned long **D = new unsigned long*[N + 1];

	for (int i = 1; i <= N; i++)
		D[i] = new unsigned long[10];

	for (int i = 0; i < 10; i++)
		D[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			unsigned long sum = 0;

			for (int k = j; k >= 0; k--)
				sum += D[i - 1][k];

			D[i][j] = sum % 10007;
		}
	}

	// 배열이 다 채워졌으므로 최종 해를 구하자! 경우를 맨 끝의 수를 10개로 나눴으므로 다 더한다.
	unsigned long result = 0;

	for (int i = 0; i < 10; i++)
		result += D[N][i];

	cout << result % 10007 << endl;

	return 0;
}