#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int dr[4] = { 0, 0, 1, -1 };
	int dc[4] = { 1, -1, 0, 0 };
	bool check[300][300] = { false };
	int R;
	int C;

	bool isInsie(int r, int c) {
		if (0 <= r && r < R && 0 <= c && c < C)
			return true;

		return false;
	}

	void bfs(int r, int c, vector<vector<char>>& grid) {
		queue<pair<int, int>> q;
		q.push(make_pair(r, c));

		check[r][c] = true;

		while (!q.empty()) {
			r = q.front().first;
			c = q.front().second;

			q.pop();
			
			// 상하좌우 탐색
			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];

				// 범위를 벗어난 경우
				if (!isInsie(nr, nc))
					continue;

				// 육지가 아닌 경우
				if (grid[nr][nc] == '0')
					continue;

				// 이미 방문한 경우
				if (check[nr][nc])
					continue;

				q.push(make_pair(nr, nc));
				check[nr][nc] = true;
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		R = grid.size();
		C = grid[0].size();
		int ans = 0;

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				// 육지이며, 아직 방문 안 했으면 탐색 시작!
				if (grid[r][c] == '1' && !check[r][c]) {
					bfs(r, c, grid);
					ans++;
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<char>> v = {
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'}
	};
	sol.numIslands(v);
}