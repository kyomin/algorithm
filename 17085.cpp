#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
char map[15][15];
int answer = 0;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int getSize(int r, int c) {
	int ret = 0;

	while (1) {
		bool flag = true;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i] * ret;
			int nc = c + dc[i] * ret;
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || map[nr][nc] != '#') {
				flag = false;
				break;
			}
		}

		if (flag) 
			ret++;
		else 
			break;
	}

	return ret - 1;
}

void make_cross(int r, int c, int k, int val) {
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < 4; j++) {
			int nr = r + dr[j] * i;
			int nc = c + dc[j] * i;
			map[nr][nc] = val;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];		

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '#') {
				int step1 = getSize(i, j);
				for (int k = 0; k <= step1; k++) {
					make_cross(i, j, k, '*');

					for (int r = 0; r < N; r++) {
						for (int c = 0; c < M; c++) {
							if (map[r][c] == '#') {
								int step2 = getSize(r, c);
								int width1 = 4 * k + 1;
								int width2 = 4 * step2 + 1;
								answer = max(answer, width1*width2);
							}
						}
					}

					make_cross(i, j, k, '#');
				}
			}
		}
	}

	cout << answer << endl;

	return 0;
}