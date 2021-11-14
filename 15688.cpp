#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> nums;
	int N;
	cin >> N;
	nums.resize(N);


	for (int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	for (int i = 0; i < N; i++)
		cout << nums[i] << '\n';

	return 0;
}