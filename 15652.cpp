#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> vc;	// 출력할 것 담기

void DFS(int start) {
	if (vc.size() == M) {
		for (auto i : vc)
			cout << i << ' ';

		cout << '\n';

		return;
	}

	for (int i = start; i <= N; i++) {
		vc.push_back(i);

		DFS(i);

		vc.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	DFS(1);

	return 0;
}