#include <iostream>
#include <vector>

using namespace std;

int results[100001];
int a[100001];

void dfs(int node, int w) {
	results[node] += w;

	if (a[node] != 0) {
		dfs(a[node], w);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int employee;
		cin >> employee;
		if (employee != -1) {
			a[employee] = i;
		}
	}
		
	for (int i = 0; i < m; i++) {
		int employee, w;
		cin >> employee >> w;

		dfs(employee, w);
	}
	
	for (int i = 1; i <= n; i++) {
		cout << results[i] << ' ';
	}

	cout << endl;

	return 0;
}