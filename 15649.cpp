#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vc;
bool visit[9];

void DFS() {
	// M�� �������� ��� �� ����!
	if (vc.size() == M) {
		for (auto i : vc)
			cout << i << ' ';

		cout << '\n';

		return;
	}

	for (int i = 1; i <= N; i++) {
		// vc�� ����� �ʾҴٸ�
		if (!visit[i]) {
			visit[i] = true;
			vc.push_back(i);

			DFS();

			vc.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	DFS();

	return 0;
}