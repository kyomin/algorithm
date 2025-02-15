#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const pair<string, int> &p1, const pair<string, int> &p2) {
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first > p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	map<string, int> m;
	vector<pair<string, int>> v;
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string s;
		cin >> s;

		if (m.find(s) == m.end())
			m[s] = 1;
		else
			m.find(s)->second += 1;
	}

	copy(m.begin(), m.end(), back_inserter(v));

	sort(v.begin(), v.end(), comp);

	cout << v[0].first << ' ' << v[0].second << endl;

	return 0;
}