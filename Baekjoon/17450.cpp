#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char snacks[3] = { 'S', 'N', 'U' };

bool comp(const pair<char, float> &p1, const pair<char, float> &p2) {
	if (p1.second > p2.second)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<pair<char, float>> v;

	for (int i = 0; i < 3; i++) {
		float p, w;
		cin >> p >> w;

		if (p * 10 >= 5000) {
			v.push_back(
				make_pair(
					snacks[i],
					(w * 10) / (p * 10 - 500)
				)
			);
		}
		else {
			v.push_back(
				make_pair(
					snacks[i],
					(w * 10) / (p * 10)
				)
			);
		}
	}

	sort(v.begin(), v.end(), comp);

	cout << v[0].first << '\n';

	return 0;
}