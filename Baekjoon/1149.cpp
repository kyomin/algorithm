#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// ���� ����
	int N;
	cin >> N;

	// ��ĥ ����� ���� ���
	int **W = new int*[N + 1];

	for (int i = 1; i <= N; i++)
		W[i] = new int[3];

	// ��ĥ ��� �Է�!
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> W[i][j];

	// ���� �ظ� ���� ���
	int **DP = new int*[N + 1];

	for (int i = 1; i <= N; i++)
		DP[i] = new int[3];

	// ���� ���� ������ �ڸ��� �ظ� ���� �ִ´�.
	DP[1][0] = W[1][0];
	DP[1][1] = W[1][1];
	DP[1][2] = W[1][2];

	// ���� ������ 1����� ���� ó��!
	if (N == 1) {
		cout << min(min(DP[1][0], DP[1][1]), DP[1][2]) << endl;
		return 0;
	}

	// DP�� �迭�� �ּ��� �غ��� ä��������.
	for (int i = 2; i <= N; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + W[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + W[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + W[i][2];
	}

	cout << min(min(DP[N][0], DP[N][1]), DP[N][2]) << endl;

	return 0;
}