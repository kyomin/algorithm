#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int N;
	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int idx = N / 2;

	cout << v[idx] << '\n';

	return 0;
}