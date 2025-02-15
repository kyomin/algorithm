#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int dr[4] = { 1, -1, 0, 0 };
	int dc[4] = { 0, 0, 1, -1 };
	bool check[50][50] = { false };
	vector<vector<int>> ret_image;
	int R, C;
	int cur_color;

	bool isInside(int r, int c) {
		if (0 <= r && r < R && 0 <= c && c < C)
			return true;

		return false;
	}

	void bfs(int r, int c, int new_color) {
		queue<pair<int, int>> q;
		q.push(make_pair(r, c));

		check[r][c] = true;
		ret_image[r][c] = new_color;
		
		while (!q.empty()) {
			r = q.front().first;
			c = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];

				// 범위 내에 없다면
				if (!isInside(nr, nc))
					continue;

				// 이미 방문한 곳이라면
				if (check[nr][nc])
					continue;

				// 현재 색깔과 연결되지 않는다면
				if (ret_image[nr][nc] != cur_color)
					continue;

				q.push(make_pair(nr, nc));
				check[nr][nc] = true;
				ret_image[nr][nc] = new_color;
			}
		}
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		R = image.size();
		C = image[0].size();
		cur_color = image[sr][sc];

		for (int r = 0; r < R; r++) {
			vector<int> row;

			for (int c = 0; c < C; c++)
				row.push_back(image[r][c]);

			ret_image.push_back(row);
		}

		bfs(sr, sc, newColor);

		return ret_image;
	}
};