#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Point {
	int row;
	int col;
	int dist;
};

int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool bfs(vector<string> place, int row, int col) {
	bool visited[5][5] = { false };
	queue<Point> q;
	
	visited[row][col] = true;
	q.push({ row, col, 0 });

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (curr.dist > 2)
			continue;

		if (curr.dist != 0 && place[curr.row][curr.col] == 'P')
			return false;

		for (int i = 0; i < 4; i++) {
			int nr = curr.row + d[i][0];
			int nc = curr.col + d[i][1];

			if (nr < 0 || nr>4 || nc < 0 || nc>4)
				continue;

			if (visited[nr][nc])
				continue;

			if (place[nr][nc] == 'X')
				continue;

			visited[nr][nc] = true;
			q.push({ nr, nc, curr.dist + 1 });
		}
	}

	return true;
}

bool check(vector<string> place) {
	for (int r = 0; r < 5; r++)
		for (int c = 0; c < 5; c++)
			if (place[r][c] == 'P')
				if (!bfs(place, r, c))
					return false;
	
	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (auto place : places) {
		if (check(place))
			answer.push_back(1);
		else
			answer.push_back(0);
	}

	return answer;
}