#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

int visited[2][500001];

bool chk(int loc) {
	if (0 <= loc && loc <= 500000) 
		return true;
	else 
		return false;
}

int main() {
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> que;
	que.push(make_pair(N, 0));
	visited[0][N] = 0;
	memset(visited, -1, sizeof(visited));

	while (!que.empty()) {
		int subinLoc = que.front().first;
		int subinTime = que.front().second;
		que.pop();

		if (chk(subinLoc) == false) continue;
		if (visited[subinTime % 2][subinLoc] != -1) continue;

		visited[subinTime % 2][subinLoc] = subinTime;

		que.push(make_pair(subinLoc - 1, subinTime + 1));
		que.push(make_pair(subinLoc + 1, subinTime + 1));
		que.push(make_pair(subinLoc * 2, subinTime + 1));
	}

	bool flag = false;
	for (int i = 0; i <= 500000; i++) {
		int nextK = K + (i*(i + 1)) / 2;
		if (nextK > 500000) break;
		if (visited[i % 2][nextK] != -1 && visited[i % 2][nextK] <= i) {
			cout << i << endl;
			flag = true;
			break;
		}
	}

	if (!flag) 
		cout << -1 << endl;

	return 0;
}