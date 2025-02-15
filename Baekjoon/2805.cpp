#include <iostream>

using namespace std;

int main() {
	unsigned long long lo = 0, hi = 1000000000;
	unsigned long long N, M, height[1000000];
	cin >> N >> M;

	for (unsigned long long i = 0; i < N; i++)
		cin >> height[i];

	// �̺� Ž�� ����
	while (lo + 1 < hi) {
		unsigned long long mid = (lo + hi) / 2;

		// �� ������ ���ؼ� mid�� ���ܱ� ���� ������ ���� ����� ���� ���� ���Ѵ�.
		unsigned long long sum = 0;

		for (unsigned long long i = 0; i < N; i++)
			if (height[i] > mid)
				sum += (height[i] - mid);

		// mid�� M �̻��� ���̸� ������ �� �ִ� ���
		if (sum >= M)
			lo = mid;
		else
			hi = mid;
	}

	cout << lo << endl;

	return 0;
}