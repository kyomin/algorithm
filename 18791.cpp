#include <iostream>
#include <vector>

using namespace std;

int N;
bool found;
vector<int> vc;
vector<int> arr;


void dfs(int cnt) {
	if (vc.size() == N) {
		int sum = 0;

		for (auto i : vc) {
			sum += i;
		}

		// 해답을 찾은 경우
		if (sum % N == 0) {
			for (auto i : vc) {
				cout << i << ' ';
			}

			cout << endl;

			found = true;

			return;
		}

		return;
	}

	for (int i = cnt; i < (2 * N - 1); i++) {
		if (vc.size() < N) {
			vc.push_back(arr[i]);

			dfs(i + 1);

			if (found)
				return;

			vc.pop_back();
		}
	}
}

int main() {
	cin >> N;

	arr.resize(2 * N - 1);

	for (int i = 0; i < 2 * N - 1; i++)
		cin >> arr[i];

	dfs(0);

	if (!found)
		cout << -1 << '\n';

	return 0;
}