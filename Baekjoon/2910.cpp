#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s {
	int frequency;
	int order;
}S;

bool com(const pair<int, S> &p1, const pair<int, S> &p2) {
	if (p1.second.frequency > p2.second.frequency)
		return true;
	else if (p1.second.frequency == p2.second.frequency)
		if (p1.second.order < p2.second.order)
			return true;
		else
			return false;
	else
		return false;
}

int main() {
	map<int, S> m;
	vector<pair<int, S>> v;

	int count = 1;
	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		// 해당 키를 못 찾았다면
		if (m.find(n) == m.end()) {
			S s;
			s.frequency = 1;
			s.order = count;

			m[n] = s;

			count += 1;
		}
		// 해당 키를 찾았다면
		else
			// 빈도 증가!
			m.find(n)->second.frequency += 1;
	}

	// map 변수 m에 값이다 담겼을 것이다.
	// 이를 pair를 이용하여 벡터에 담자.
	copy(m.begin(), m.end(), back_inserter(v));
	sort(v.begin(), v.end(), com);

	int len = v.size();

	for (int i = 0; i < len; i++)
		for (int j = 0; j < v[i].second.frequency; j++)
			cout << v[i].first << ' ';
		
	cout << endl;

	return 0;
}