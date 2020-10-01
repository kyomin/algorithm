#include <iostream>

using namespace std;

int N;
int dp[1000001];
int before[1000001];	// �� ������ ��� ���� �迭

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	before[1] = -1;
	cin >> N;

	for (int n = 2; n <= N; n++) {
		// 1�� ���� ����� ���� �׻� �����ϰ�, 
		// ���� ���� Ƚ���� ���� �ϹǷ�
		dp[n] = dp[n - 1] + 1;
		before[n] = n - 1;

		// 2�� ������ ���� ���� ��
		if (n % 2 == 0 && dp[n] > dp[n / 2] + 1) {
			dp[n] = dp[n / 2] + 1;
			before[n] = n / 2;
		}

		// 3���� ������ ���� ���� ��
		if (n % 3 == 0 && dp[n] > dp[n / 3] + 1) {
			dp[n] = dp[n / 3] + 1;
			before[n] = n / 3;
		}
	}

	cout << dp[N] << endl;

	while (N != -1) {
		cout << N << ' ';

		N = before[N];
	}

	return 0;
}