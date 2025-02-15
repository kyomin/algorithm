#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	set<int> s1, s2;
	vector<int> vd1, vd2;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		s1.insert(n);
	}

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		s2.insert(n);
	}

	// s1-s2
	set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(vd1));

	// s2-s1
	set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(vd2));

	cout << vd1.size() + vd2.size() << '\n';

	return 0;
}