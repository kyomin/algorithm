#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.first < p2.first) {
		return true;
	}
	else if (p1.first == p2.first) {
		if (p1.second < p2.second)
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}

int solution(vector<int> array, int n) {
	vector<pair<int, int>> v;	// first: diff, second: number

	for (int num : array) {
		int d = (int)abs(n - num);

		v.push_back(make_pair(d, num));
	}

	sort(v.begin(), v.end(), comp);

	return v[0].second;
}