#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[10001];

// first: pay, second: day
bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.first > p2.first) {
		return true;
	}
	else if (p1.first == p2.first) {
		if (p1.second > p2.second)
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}

int main() {
	vector<pair<int, int>> info;
	int N;
	int ans = 0;
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int p, d;
		cin >> p >> d;

		info.push_back(make_pair(p, d));
	}

	sort(info.begin(), info.end(), comp);

	for (int i = 0; i < N; i++) {
		int p = info[i].first;
		int d = info[i].second;

		// d일 안에 가능한 날짜 탐색!
		for (int j = d; j >= 1; j--) {
			if (!visited[j]) {
				visited[j] = true;
				ans += p;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}