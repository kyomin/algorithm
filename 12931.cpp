#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> a(N, 0), b(N);

	for (auto& i : b)
		cin >> i;

	// B -> A
	int cnt = 0;
	while (true) {
		int zeroCount = 0;

		// 1 ���� Ƚ�� ���ϱ�
		for (auto& i : b) {
			if (i % 2) {
				cnt++;
				i--;
			}

			if (i == 0)
				zeroCount++;
		}

		// A �迭(��� ���Ұ� 0�� �迭)�� ������ ���
		if (zeroCount == N)
			break;

		// 2 ���� Ƚ�� ���ϱ�
		cnt++;

		for (auto& i : b)
			i /= 2;
	}

	cout << cnt << endl;

	return 0;
}