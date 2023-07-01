#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visited[2000] = { 0 };
vector<int> vecArr[2000];
bool flag = false;

void dfs(int start, int depth) {
	visited[start] = 1;

	if (depth == 4) {
		flag = true;
		cout << 1 << "\n";
		return;
	}

	for (int i = 0; i < vecArr[start].size(); i++) {
		if (visited[vecArr[start][i]] == 0 && !flag) {
			dfs(vecArr[start][i], depth + 1);
		}
	}

	visited[start] = 0;
}

int main() {
	queue<int> que;
	int N, M;
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		vecArr[a].push_back(b);
		vecArr[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		dfs(i, 0);
	}

	if (!flag) 
		cout << 0;

	return 0;
}