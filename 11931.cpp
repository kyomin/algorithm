#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool com(const int &n1, const int &n2) {
	if (n1 > n2)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<long long> v;
	unsigned long N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		v.push_back(n);
	}

	sort(v.begin(), v.end(), com);

	for (int i = 0; i < N; i++)
		cout << v[i] << '\n';

	return 0;
}