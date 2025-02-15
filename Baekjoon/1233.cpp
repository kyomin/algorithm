#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

// first : 합, second : 빈도수
bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second > p2.second)
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
	map<int, int> m;
	vector<pair<int, int>> v;
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				int sum = i + j + k;

				// 해당 키(합)를 못 찾았다면 등록
				if (m.find(sum) == m.end())
					m[sum] = 1;
				else // 찾았다면 빈도수 증가
					m.find(sum)->second += 1;
			}
		}
	}

	// map to vector
	copy(m.begin(), m.end(), back_inserter(v));

	sort(v.begin(), v.end(), comp);

	cout << v[0].first << endl;

	return 0;
}