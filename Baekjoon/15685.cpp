#include <iostream>
#include <vector>

using namespace std;

bool visited[101][101];
pair<int, int> end_point;
int x, y, d, g, N;

// 0:우, 1:상, 2:좌, 3:하
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	cin >> N;

	for (int t = 0; t < N; t++) {
		cin >> x >> y >> d >> g;

		vector<int> directions;

		// 시작점 먼저 방문했다 체크!
		visited[y][x] = true;

		// 0세대 먼저 계산
		x += dx[d];
		y += dy[d];

		visited[y][x] = true;

		end_point = make_pair(x, y);

		directions.push_back(d);

		// 입력한 세대만큼 작업 개시!
		for (int i = 1; i <= g; i++) {
			int len = directions.size();
			vector<int> temp;

			// 거꾸로 빼내면서 작업하자!
			for (int a = len - 1; a >= 0; a--) {
				d = directions[a];

				// 시계방향으로 회전!
				if (d == 0)
					d = 3;
				else
					d -= 1;

				// 그리고 방향 뒤집기!
				if (d - 2 < 0)
					d += 2;
				else
					d -= 2;

				end_point.first += dx[d];
				end_point.second += dy[d];

				visited[end_point.second][end_point.first] = true;

				temp.push_back(d);
			}

			directions.insert(directions.end(), temp.begin(), temp.end());
		}
	}

	int result = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (
				visited[i][j] &&
				visited[i + 1][j] &&
				visited[i][j + 1] &&
				visited[i + 1][j + 1]
				)
				result += 1;
		}
	}

	cout << result << '\n';

	return 0;
}