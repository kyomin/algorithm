#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> nums;
	int N, M;
	cin >> N >> M;

	nums.resize(N);

	for (int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		int lower = lower_bound(nums.begin(), nums.end(), num) - nums.begin();

		if (lower < N) {
			if(num == nums[lower])
				cout << lower << '\n';
			else
				cout << -1 << '\n';
		}			
		else {
			cout << -1 << '\n';
		}			
	}

	return 0;
}