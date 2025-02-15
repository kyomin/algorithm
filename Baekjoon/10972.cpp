#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	vector<int> v;

	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	if (next_permutation(v.begin(), v.end())) {
		for (auto num : v)
			cout << num << ' ';

		cout << '\n';
	}
	else
		cout << -1 << '\n';

	return 0;
}