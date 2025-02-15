#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int S[101];		// 인접 리스트
bool visited[101];
bool finished[101];

vector<int> result;

void dfs(int curr) {
	visited[curr] = true;

	// 다음 정점 담기
	int next = S[curr];

	if (visited[next]) {	// 다음 정점 이미 방문
		if (!finished[next]) {	// 사이클이 형성
			for (int temp = next; temp != curr; temp = S[temp])
				result.push_back(temp);

			// 현재 자기 자신 담기
			result.push_back(curr);
		}
	}
	else
		dfs(next);

	finished[curr] = true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		S[i] = n;
	}

	for (int i = 1; i <= N; i++)
		if (!visited[i])
			dfs(i);

	// 크기 순으로 정렬
	sort(result.begin(), result.end());

	int len = result.size();

	cout << len << '\n';

	for (int i = 0; i < len; i++)
		cout << result[i] << '\n';

	return 0;
}