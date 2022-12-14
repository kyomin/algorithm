#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int originK;
vector<vector<int>> originDungeons;
vector<vector<int>> copyDungeons;
int N;
bool visit[8];
int answer = 0;

void dfs() {
	if (copyDungeons.size() == N) {
		int copyK = originK;
		int cnt = 0;

		for (auto dungeon : copyDungeons) {
			int minTiredness = dungeon[0];
			int consumeTiredness = dungeon[1];

			if (copyK < minTiredness)
				break;

			copyK -= consumeTiredness;
			cnt++;
		}

		answer = max(answer, cnt);

		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			copyDungeons.push_back(originDungeons[i]);

			dfs();

			copyDungeons.pop_back();
			visit[i] = false;
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	originK = k;
	originDungeons = dungeons;
	N = dungeons.size();

	dfs();

	return answer;
}