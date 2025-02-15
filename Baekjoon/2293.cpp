#include <iostream>
#include <algorithm>

using namespace std;

int Coin[100];
unsigned long DP[100001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		Coin[i] = num;
	}

	// 동전의 가치는 먼저 정렬을 하고서 접근한다.
	sort(Coin, Coin + n);

	for (int i = 1; i <= k; i++)
		DP[i] = 0;

	DP[0] = 1;

	for (int i = 0; i < n; i++) {
		// 만일 첫 코인이라면
		// 그의 배수가 되는 것만 경우의 수 1로 만든다.
		if (i == 0) {
			for (int j = Coin[i]; j <= k; j++)
				if (j%Coin[i] == 0)
					DP[j] += 1;

			continue;
		}

		// 첫 코인이 아니라면 다음을 시행한다.
		for (int j = Coin[i]; j <= k; j++)
			// 기존의 값으로 만들었던 것 + 새로운 동전으로 만들 수 있는 것
			DP[j] += DP[j - Coin[i]];
	}

	// 출력!
	cout << DP[k] << endl;

	return 0;
}