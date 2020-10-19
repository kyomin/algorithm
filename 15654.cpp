#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vc;	// ����� �� ���
vector<int> arr;	// N���� �� ���
bool visit[10001];

void DFS() {
	// M�� �������� ��� �� ����!
	if (vc.size() == M) {
		for (auto i : vc)
			cout << i << ' ';

		cout << '\n';

		return;
	}

	for (int i = 0; i < N; i++) {
		// vc�� ����� �ʾҴٸ�
		if (!visit[arr[i]]) {
			visit[arr[i]] = true;
			vc.push_back(arr[i]);

			DFS();

			vc.pop_back();
			visit[arr[i]] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	DFS();

	return 0;
}