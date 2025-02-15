#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Point {
	int row;
	int col;
	int cnt;	// ���� Ƚ��
};

vector<vector<int>> Board;	// board ������ ���� ����ȭ

const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, 1, -1 };

/*	
	src���� dest�� ���� �ּ� ���� Ƚ���� bfs Ž���Ѵ�

	@param src		���� ��ġ
	@param dest		���� ��ġ

	@return			�ּ� ���� Ƚ��
*/
int bfs(Point src, Point dest) {
	bool visited[4][4] = { false };
	queue<Point> q;

	q.push(src);

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (curr.row == dest.row && curr.col == dest.col)
			return curr.cnt;
		
		for (int i = 0; i < 4; i++) {
			int nr = curr.row + dr[i];
			int nc = curr.col + dc[i];

			// ��� Ȯ��
			if (nr < 0 || nr>3 || nc < 0 || nc>3)
				continue;

			// ����Ű�� �̵��ϴ� ���
			if (!visited[nr][nc]) {
				visited[nr][nc] = true;
				q.push({ nr, nc, curr.cnt + 1 });
			}

			// Ctrl + ����Ű�� �̵��ϴ� ���
			for (int j = 0; j < 2; j++) {
				if (Board[nr][nc] != 0)
					break;

				if (
					nr + dr[i] < 0 ||
					nr + dr[i] > 3 ||
					nc + dc[i] < 0 ||
					nc + dc[i] > 3
					)
					break;

				nr += dr[i];
				nc += dc[i];
			}

			if (!visited[nr][nc]) {
				visited[nr][nc] = true;
				q.push({ nr, nc, curr.cnt + 1 });
			}
		}
	}
	
	return INF;
}

/*
	������ ������ ��� ����� ���� ���Ѵ�

	@param src		���� ��ġ

	@return			���� ��ġ���� �����ؼ� ��� ī�带 �����ϴ� ���� Ƚ��
*/
int permutate(Point src) {
	int ret = INF;

	for (int num = 1; num <= 6; num++) {
		vector<Point> card;

		// 4 x 4 board Ž���Ͽ� ���� �׸�ī�� ��ġ ����
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (Board[i][j] == num)
					card.push_back({ i, j, 0 });				

		// �̹� ���ŵǾ� �׸�ī�尡 ���� ��� skip
		if (card.empty())
			continue;

		// ���� ������ �� ���� ���̽��� ������.
		int one = bfs(src, card[0]) + bfs(card[0], card[1]) + 2;
		int two = bfs(src, card[1]) + bfs(card[1], card[0]) + 2;

		// ������ ī�� ����
		for (int i = 0; i < 2; i++)
			Board[card[i].row][card[i].col] = 0;
		
		ret = min(ret, one + permutate(card[1]));
		ret = min(ret, two + permutate(card[0]));

		// ������ ����
		for (int i = 0; i < 2; i++)
			Board[card[i].row][card[i].col] = num;
	}

	// ��� ī�尡 ���ŵǾ� �ִٸ�
	if (ret == INF)
		return 0;

	return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
	Board = board;

	return permutate({ r, c, 0 });
}