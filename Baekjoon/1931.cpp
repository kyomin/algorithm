#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second < p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	vector<pair<int, int>> meeting_times;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;

		meeting_times.push_back(make_pair(s, e));
	}

	sort(meeting_times.begin(), meeting_times.end(), comp);

	int ans = 1;
	int end = meeting_times[0].second;

	for (int i = 1; i < N; i++) {
		int s = meeting_times[i].first;
		int e = meeting_times[i].second;

		if (s >= end) {
			ans++;
			end = e;
		}
	}

	cout << ans << '\n';

	return 0;
}