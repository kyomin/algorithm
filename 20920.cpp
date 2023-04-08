#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool com(const pair<string, int> &p1, const pair<string, int> &p2) {
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first.length() > p2.first.length())
			return true;
		else if (p1.first.length() == p2.first.length()) {
			if (p1.first < p2.first)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	map<string, int> m;
	vector<pair<string, int>> v;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;

		if (word.length() < M)
			continue;

		if (m.find(word) == m.end())
			m[word] = 1;
		else
			m.find(word)->second += 1;
	}

	copy(m.begin(), m.end(), back_inserter(v));
	sort(v.begin(), v.end(), com);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << '\n';

	return 0;
}