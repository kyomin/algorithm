#include <iostream>
#include <vector>

using namespace std;

vector<int> container;
int M, N;

void dfs() {
	if (container.size() == N) {
		for (auto i : container)
			cout << i << ' ';

		cout << '\n';

		return;
	}

	for (int i = 1; i <= M; i++) {
		container.push_back(i);

		dfs();

		container.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;

	dfs();

	return 0;
}