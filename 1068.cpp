#include <iostream>
#include <vector>

using namespace std;

int parents[50];
bool check[50];
vector<int> a[50];
int ans;

void dfs(int node) {
	check[node] = true;

	// 다음으로 내려갈 수 없는 경우 => 리프 노드
	if (a[node].size() == 0) {
		ans++;
		return;
	}
	
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];

		if (!check[next])
			dfs(next);
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> parents[i];

	int root_node;
	int erasing_node;
	cin >> erasing_node;

	for (int i = 0; i < N; i++) {
		int parent = parents[i];

		if (parent == -1) {
			root_node = i;
			continue;
		}

		// 지울 노드라면 부모와 연결하지 않는다
		if (i == erasing_node) continue;

		// 부모 -> 자식으로 뻗어 나가는 모양이므로
		a[parent].push_back(i);
	}

	if(root_node != erasing_node)
		dfs(root_node);

	cout << ans << '\n';

	return 0;
}