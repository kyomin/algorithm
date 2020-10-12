#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int R, C;
int result = 0;
string a[20];

// 0 ~ 25 => 'A' ~ 'Z'
bool visited[26] = { false, };

void DFS(int x, int y, char alpha, int cnt) {
	visited[alpha - 'A'] = true;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		// 범위 내에 있고
		if (0 <= nx && nx < R && 0 <= ny && ny < C)
			// 새로운 알파벳일 경우!
			if (!visited[a[nx][ny] - 'A'])
				DFS(nx, ny, a[nx][ny], cnt + 1);
	}

	visited[alpha - 'A'] = false;

	result = max(result, cnt);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		cin >> a[i];

	DFS(0, 0, a[0][0], 1);

	cout << result << '\n';

	return 0;
}