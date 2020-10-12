#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	// ���� ������ ���� ���� ����
	int max = (2 * N) - 1;

	for (int i = 1; i <= N; i++) {
		// ���� ���� ���� ����
		int num_of_star = (i * 2) - 1;

		// ���� ������ �����ϴ� �ε���
		int start = (max - num_of_star) / 2;

		// ����Ⱑ ������ �ε���
		int end = start + (num_of_star - 1);

		for (int j = 0; j <= end; j++) {
			if (j >= start && j <= end)
				cout << '*';
			else
				cout << ' ';
		}

		// ���� ������ ������ �����ش�.
		cout << '\n';
	}

	return 0;
}