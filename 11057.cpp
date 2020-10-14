#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	unsigned long **D = new unsigned long*[N + 1];

	for (int i = 1; i <= N; i++)
		D[i] = new unsigned long[10];

	for (int i = 0; i < 10; i++)
		D[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			unsigned long sum = 0;

			for (int k = j; k >= 0; k--)
				sum += D[i - 1][k];

			D[i][j] = sum % 10007;
		}
	}

	// �迭�� �� ä�������Ƿ� ���� �ظ� ������! ��츦 �� ���� ���� 10���� �������Ƿ� �� ���Ѵ�.
	unsigned long result = 0;

	for (int i = 0; i < 10; i++)
		result += D[N][i];

	cout << result % 10007 << endl;

	return 0;
}