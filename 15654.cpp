#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vc;	// 출력할 것 담기
vector<int> arr;	// N개의 수 담기
bool visit[10001];

void DFS() {
	// M과 같아지면 출력 후 종료!
	if (vc.size() == M) {
		for (auto i : vc)
			cout << i << ' ';

		cout << '\n';

		return;
	}

	for (int i = 0; i < N; i++) {
		// vc에 담기지 않았다면
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