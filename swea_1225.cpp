#include <iostream>

using namespace std;

int nums[8];

void solution() {
	int descent_num = 1;

	while (true) {
		// 감소하는 숫자가 주기를 넘을 경우, 다시 처음으로 회귀한다.
		if (descent_num > 5)
			descent_num = 1;

		// 첫 원소를 감소시킨다.
		nums[0] -= descent_num;

		// rotate!
		int temp = nums[0];

		for (int i = 0; i < 7; i++)
			nums[i] = nums[i + 1];

		nums[7] = temp;

		// 감소 후 0보다 작아지거나 같을 경우 해당 배열이 암호가 된다.
		if (nums[7] <= 0) {
			nums[7] = 0;
			break;
		}

		descent_num++;
	}
}

int main() {
	for (int t = 1; t <= 10; t++) {
		int T;
		cin >> T;

		for (int i = 0; i < 8; i++)
			cin >> nums[i];

		solution();

		cout << '#' << t << ' ';

		for (int i = 0; i < 7; i++)
			cout << nums[i] << ' ';

		cout << nums[7] << '\n';
	}

	return 0;
}