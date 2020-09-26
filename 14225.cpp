#include <iostream>
#include <vector>

using namespace std;

bool check[2000001];
int arr[20];

vector<int> vc;

int N, M;

void dfs(int cnt) {
	if (vc.size() == M) {
		int sum = 0;

		for (auto num : vc) {
			sum += num;
		}

		// 만들 수 있는 수에 대해 체크
		check[sum] = true;

		return;
	}

	for (int i = cnt; i < N; i++) {
		if (vc.size() < M) {
			vc.push_back(arr[i]);

			dfs(i + 1);

			vc.pop_back();
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		M = i;
		vc.clear();

		dfs(0);
	}

	for (int i = 1; i <= 2000000; i++) {
		if (!check[i]) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}