#include <iostream>
#include <vector>

using namespace std;

int parents[50];
bool check[50];
vector<int> a[50];
int ans;

void dfs(int node) {
	check[node] = true;

	// �������� ������ �� ���� ��� => ���� ���
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

		// ���� ����� �θ�� �������� �ʴ´�
		if (i == erasing_node) continue;

		// �θ� -> �ڽ����� ���� ������ ����̹Ƿ�
		a[parent].push_back(i);
	}

	if(root_node != erasing_node)
		dfs(root_node);

	cout << ans << '\n';

	return 0;
}