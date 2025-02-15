#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;

int map[20][20];
int visited[20][20];
int N, M;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int answer = 0;

vector<pair<int, int>> spaceVec;
vector<pair<int, int>> partnerGroup_StartLoc;
vector<int> pickedIdxVec;

int picked[400] = { 0, };

void bfs(int r, int c) {
	visited[r][c] = 1;
	queue<pair<int, int>> que;
	que.push(make_pair(r, c));

	while (!que.empty()) {
		int cr = que.front().first;
		int cc = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] == 1 || map[nr][nc] != 2) continue;

			visited[nr][nc] = 1;
			que.push(make_pair(nr, nc));
		}
	}
}

int getKilled() {
	int ret = 0;
	int v[20][20];

	for (int i = 0; i < partnerGroup_StartLoc.size(); i++) {
		queue<pair<int, int>> tmpQue;
		memset(v, 0, sizeof(v));
		int r = partnerGroup_StartLoc[i].first;
		int c = partnerGroup_StartLoc[i].second;

		v[r][c] = 1;
		int killedCnt = 1;
		bool isContinue = true;

		tmpQue.push(make_pair(r, c));
		while (!tmpQue.empty()) {
			int cr = tmpQue.front().first;
			int cc = tmpQue.front().second;
			tmpQue.pop();

			for (int k = 0; k < 4; k++) {
				int nr = cr + dr[k];
				int nc = cc + dc[k];
				if (nr < 0 || nr >= N || nc < 0 || nc >= M || v[nr][nc] == 1) continue;

				if (map[nr][nc] == 0) {
					isContinue = false;
					break;
				}
				
				if (map[nr][nc] == 2) {
					v[nr][nc] = 1;
					killedCnt++;
					tmpQue.push(make_pair(nr, nc));
				}
			}

			if (!isContinue) 
				break;
		}

		if (isContinue)
			ret += killedCnt;		
	}

	return ret;
}

void pickDFS(int toPick) {
	if (toPick == 0) {
		int r1 = spaceVec[pickedIdxVec[0]].first;
		int c1 = spaceVec[pickedIdxVec[0]].second;

		int r2 = spaceVec[pickedIdxVec[1]].first;
		int c2 = spaceVec[pickedIdxVec[1]].second;

		map[r1][c1] = 1; map[r2][c2] = 1;
		int sum = getKilled();
		answer = max(answer, sum);
		map[r1][c1] = 0; map[r2][c2] = 0;

		return;
	}

	for (int i = 0; i < spaceVec.size(); i++) {
		if (picked[i] == 0) {
			picked[i] = 1;
			pickedIdxVec.push_back(i);
			pickDFS(toPick - 1);
			pickedIdxVec.pop_back();
			picked[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) 
				spaceVec.push_back(make_pair(i, j));
		}
	}

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2 && visited[i][j] == 0) {
				partnerGroup_StartLoc.push_back(make_pair(i, j));
				bfs(i, j);
			}
		}
	}

	pickDFS(2);
	cout << answer;

	return 0;
}