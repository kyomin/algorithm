#include <iostream>
#include <vector>
using namespace std;

int N, M, ans;
bool visit[201][201];
vector<int> vc;

bool canEat() {
	if (visit[vc[0]][vc[1]] || visit[vc[1]][vc[2]] || visit[vc[0]][vc[2]])
		return false;

	return true;
}

void dfs(int cnt) {
	if (vc.size() == 3) {
		if (canEat())
			ans++;

		return;
	}

	for (int i = cnt; i <= N; i++) {
		if (vc.size() < 3) {
			vc.push_back(i);
			dfs(i + 1);
			vc.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		visit[a][b] = true;
		visit[b][a] = true;
	}

	dfs(1);

	cout << ans << endl;

	return 0;
}