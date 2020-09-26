#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vc;
unsigned long long arr[10000];
bool visit[10000];
unsigned long long result = 0;

void dfs() {
	if (vc.size() == 2) {
		result += abs(vc[0] - vc[1]);

		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			vc.push_back(arr[i]);

			dfs();

			vc.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dfs();

	cout << result << '\n';

	return 0;
}