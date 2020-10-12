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

	// ������ ��ġ�� ���� ������ �ϰ� �����Ѵ�.
	sort(Coin, Coin + n);

	for (int i = 1; i <= k; i++)
		DP[i] = 0;

	DP[0] = 1;

	for (int i = 0; i < n; i++) {
		// ���� ù �����̶��
		// ���� ����� �Ǵ� �͸� ����� �� 1�� �����.
		if (i == 0) {
			for (int j = Coin[i]; j <= k; j++)
				if (j%Coin[i] == 0)
					DP[j] += 1;

			continue;
		}

		// ù ������ �ƴ϶�� ������ �����Ѵ�.
		for (int j = Coin[i]; j <= k; j++)
			// ������ ������ ������� �� + ���ο� �������� ���� �� �ִ� ��
			DP[j] += DP[j - Coin[i]];
	}

	// ���!
	cout << DP[k] << endl;

	return 0;
}