#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cards[5];
int max_num;
vector<int> vc;

void dfs(int cnt) {
	if (vc.size() == 3) {
		int sum = 0;

		for (auto i : vc)
			sum += i;

		int r = sum % 10;

		if (r > max_num)
			max_num = r;

		return;
	}

	for (int i = cnt; i < 5; i++) {
		if (vc.size() < 3) {
			vc.push_back(cards[i]);
			dfs(i + 1);
			vc.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> players;
	int N;
	cin >> N;

	players.resize(N);

	for (int n = 0; n < N; n++) {
		max_num = 0;
		vc.clear();

		for (int i = 0; i < 5; i++)
			cin >> cards[i];

		dfs(0);

		players[n] = max_num;
	}

	max_num = *max_element(players.begin(), players.end());

	for (int n = N - 1; n >= 0; n--) {
		if (players[n] == max_num) {
			cout << n + 1 << '\n';
			break;
		}
	}

	return 0;
}