#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

// int �ڷ����� �ִ밪�� ����� ����
const int MAX = numeric_limits<int>::max();

// �Է� �޴� ü����
string board[51];

int N, M;

// ó���� ������� �����ϴ� ü����
string whiteFirst[8] = {
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" }
};

// ó���� ���������� �����ϴ� ü����
string blackFirst[8] = {
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" }
};

// (0, 0)�� W�� ü������ �ٲ� ĭ��
int whiteFirstChange(int n, int m) {
	int cnt = 0;

	for (int i = n; i < n + 8; i++)
		for (int j = m; j < m + 8; j++)
			if (whiteFirst[i - n][j - m] != board[i][j])
				cnt++;

	return cnt;
}

// (0, 0)�� B�� ü������ �ٲ� ĭ��
int blackFirstChange(int n, int m) {
	int cnt = 0;

	for (int i = n; i < n + 8; i++)
		for (int j = m; j < m + 8; j++)
			if (blackFirst[i - n][j - m] != board[i][j])
				cnt++;

	return cnt;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int result = MAX;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	for (int i = 0; i + 8 <= N; i++)
		for (int j = 0; j + 8 <= M; j++)
			// result �� ���÷� ����
			result = min(result, min(
				whiteFirstChange(i, j),
				blackFirstChange(i, j)
			));

	cout << result << '\n';

	return 0;
}