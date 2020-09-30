#include <iostream>

using namespace std;

bool map[100][100];

int curDir = 0;
int totalRoom;
int visitedRoom = 0;
int cnt = 0;	// ������ �ٲ� Ƚ��

int M, N;

// ��, ��, ��, ��
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	// ���� �湮�ߴ� üũ
	visitedRoom += 1;
	map[y][x] = true;

	// ���� �����ߴٸ�
	if (visitedRoom == totalRoom)
		return;

	int nx = x + dx[curDir];
	int ny = y + dy[curDir];

	// ���� ���ư��� �������� �̵��� �� �ִ� ĭ�̶��
	if (0 <= nx && nx < N && 0 <= ny && ny < M && !map[ny][nx]) {
		// ������ ���ư���
		dfs(ny, nx);	
	} else {	
		// �ƴ϶�� ���� �ٲ� �� ���� ����
		curDir = (curDir + 1) % 4;
		cnt++;

		nx = x + dx[curDir];
		ny = y + dy[curDir];

		dfs(ny, nx);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	totalRoom = M * N;

	dfs(0, 0);

	cout << cnt << '\n';

	return 0;
}