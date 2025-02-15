#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

// int 자료형의 최대값을 상수로 지정
const int MAX = numeric_limits<int>::max();

// 입력 받는 체스판
string board[51];

int N, M;

// 처음이 흰색으로 시작하는 체스판
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

// 처음이 검은색으로 시작하는 체스판
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

// (0, 0)이 W인 체스판이 바뀔 칸수
int whiteFirstChange(int n, int m) {
	int cnt = 0;

	for (int i = n; i < n + 8; i++)
		for (int j = m; j < m + 8; j++)
			if (whiteFirst[i - n][j - m] != board[i][j])
				cnt++;

	return cnt;
}

// (0, 0)이 B인 체스판이 바뀔 칸수
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
			// result 값 수시로 갱신
			result = min(result, min(
				whiteFirstChange(i, j),
				blackFirstChange(i, j)
			));

	cout << result << '\n';

	return 0;
}