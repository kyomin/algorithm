#include <iostream>

using namespace std;

int nums[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int sum = 0;

	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;

		sum += num;
		nums[num]++;
	}

	int avg = sum / 10;

	int max_cnt = 0;
	int max_freq = 0;

	for (int i = 10; i <= 1000; i += 10) {
		if (nums[i] > max_cnt) {
			max_freq = i;
			max_cnt = nums[i];
		}
	}

	cout << avg << '\n';
	cout << max_freq << '\n';

	return 0;
}