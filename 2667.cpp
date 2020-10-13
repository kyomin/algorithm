#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int d[25][25];	// 단지 번호 기입용 행렬
int a[25][25];	// 집의 위치 기입용 행렬

vector<int> v;	// 각 단지의 개수를 담기 위한 벡터

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n;

// 시작 점(x, y) , 단지 번호 cnt
void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	// 우선 해당 시작 좌표에 단지번호 붙이기.
	d[x][y] = cnt;

	// 우선 하나가 세어졌으니 카운트는 1부터 시작
	int count = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// 조건을 만족하는가? => 즉, 연결 조건을 만족하는가?
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
					count += 1;	// 해당 단지의 카운트 증가
				}
			}
		}
	}

	v.push_back(count);
}

int main() {
	int cnt = 0;
	cin >> n;

	// 배열 d 초기화
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			d[i][j] = 0;

	// 배열 a 초기화
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < n; j++)
			a[i][j] = (int)(str[j] - '0');
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			// 아직 방문하지 않았다면
			if (a[i][j] == 1 && d[i][j] == 0)
				bfs(i, j, ++cnt);

	sort(v.begin(), v.end());

	// 마지막 단지 번호(총 단지의 개수) 출력!
	cout << cnt << '\n';

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i] << '\n';

	return 0;
}