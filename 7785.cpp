#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

bool comp(const pair<string, bool> &p1, const pair<string, bool> &p2) {
	if (p1.first > p2.first)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<pair<string, bool>> v;
	map<string, bool> m;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string name, status;
		cin >> name >> status;

		if (status == "enter")
			m[name] = true;
		else
			m.erase(name);
	}

	copy(m.begin(), m.end(), back_inserter(v));
	sort(v.begin(), v.end(), comp);
	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i].first << '\n';

	return 0;
}