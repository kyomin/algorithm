#include <string>
#include <vector>

using namespace std;

vector<int> a[200];
bool check[200];

void dfs(int node) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];

		if (check[next] == false)
			dfs(next);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < 200; i++)
		check[i] = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i)
				continue;

			if (computers[i][j] == 1)
				a[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			dfs(i);
			answer += 1;
		}
	}

	return answer;
}