#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> arr;
	int N;
	cin >> N;

	arr.resize(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int v;
	cin >> v;

	sort(arr.begin(), arr.end());

	int lower = lower_bound(arr.begin(), arr.end(), v) - arr.begin();
	int upper = upper_bound(arr.begin(), arr.end(), v) - arr.begin();

	cout << upper - lower << '\n';

	return 0;
}