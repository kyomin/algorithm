#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int numbers[1001];

// first : number, second : count
bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		memset(numbers, 0, sizeof(numbers));
		vector<pair<int, int>> results;

		int V;
		cin >> V;

		for (int v = 0; v < V; v++) {
			int num;
			cin >> num;

			numbers[num]++;
		}

		for (int i = 1; i <= 1000; i++) {
			// 투표가 한 번이라도 되었다면
			if (numbers[i] != 0)
				results.push_back(make_pair(i, numbers[i]));
		}

		sort(results.begin(), results.end(), comp);

		cout << results[0].first << '\n';
	}

	return 0;
}