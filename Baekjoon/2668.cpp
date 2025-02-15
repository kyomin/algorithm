#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int S[101];		// ���� ����Ʈ
bool visited[101];
bool finished[101];

vector<int> result;

void dfs(int curr) {
	visited[curr] = true;

	// ���� ���� ���
	int next = S[curr];

	if (visited[next]) {	// ���� ���� �̹� �湮
		if (!finished[next]) {	// ����Ŭ�� ����
			for (int temp = next; temp != curr; temp = S[temp])
				result.push_back(temp);

			// ���� �ڱ� �ڽ� ���
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

	// ũ�� ������ ����
	sort(result.begin(), result.end());

	int len = result.size();

	cout << len << '\n';

	for (int i = 0; i < len; i++)
		cout << result[i] << '\n';

	return 0;
}