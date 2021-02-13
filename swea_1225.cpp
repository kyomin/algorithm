#include <iostream>

using namespace std;

int nums[8];

void solution() {
	int descent_num = 1;

	while (true) {
		// �����ϴ� ���ڰ� �ֱ⸦ ���� ���, �ٽ� ó������ ȸ���Ѵ�.
		if (descent_num > 5)
			descent_num = 1;

		// ù ���Ҹ� ���ҽ�Ų��.
		nums[0] -= descent_num;

		// rotate!
		int temp = nums[0];

		for (int i = 0; i < 7; i++)
			nums[i] = nums[i + 1];

		nums[7] = temp;

		// ���� �� 0���� �۾����ų� ���� ��� �ش� �迭�� ��ȣ�� �ȴ�.
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