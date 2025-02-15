#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	vector<int> v;
	set<int> s;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		s.insert(n);
	}

	for (auto iter = s.begin(); iter != s.end(); iter++)
		v.push_back(*iter);

	sort(v.begin(), v.end());

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i] << ' ';

	cout << endl;

	return 0;
}