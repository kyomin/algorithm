#include <iostream>
#include <queue>

using namespace std;

int N, M;

int board[1001];
queue<int> dice;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> board[i];

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;

		dice.push(n);
	}

	int curPos = 1;		// 현재 위치
	int cnt = 0;		// 주사위 던진 횟수

	while (!dice.empty()) {
		int move = dice.front();
		dice.pop();
		cnt++;

		curPos += move;
		
		if (curPos >= N)
			break;

		curPos += board[curPos];

		if (curPos >= N)
			break;
	}

	cout << cnt << '\n';

	return 0;
}