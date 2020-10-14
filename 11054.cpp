#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *D1 = new int[N + 1];
	int *A1 = new int[N + 1];

	for (int i = 1; i <= N; i++)
		cin >> A1[i];

	// ���� ���� ������ �ڸ��� �ظ� �̸� �ִ´�.
	D1[1] = 1;

	// �ظ� ä�� ������.
	for (int i = 2; i <= N; i++) {
		// �� �ε����� ���� �ش� �ڱ� �ڽ��� 1�̶�� �����Ѵ�.
		D1[i] = 1;

		// ���� �÷� ������.
		for (int j = 1; j < i; j++) {
			// ���� �����̱⿡ A[j]<A[i]�̸鼭
			// ������ ���� �� ū ���� ���� upD1ate�Ѵ�.
			if (A1[j]<A1[i] && D1[j] + 1 > D1[i])
				D1[i] = D1[j] + 1;
		}
	}

	/*
		���� �۾����� �迭 D1�� ������ ��� ä������.
		�������� �����ϴ� �κм����� �ظ� ��� ���� D2�� ������ ä������.
	*/

	// �����ϴ� �κм����� �ظ� ��� ���� �迭 ���⼭�� �ش� i���� �������� ���� ��, ���� �� ���� ��Ÿ�� ���̴�.
	int *D2 = new int[N + 1];

	// ���� �迭�� ���� �Ųٷ� ��� ���� �迭
	vector<int> A2;

	// 0 �ε����� ������ �� ���!
	A2.push_back(0);

	for (int i = N; i >= 1; i--)
		A2.push_back(A1[i]);

	D2[1] = 1;

	for (int i = 2; i <= N; i++) {
		// �� �ε����� ���� �ش� �ڱ� �ڽ��� 1�̶�� �����Ѵ�.
		D2[i] = 1;

		// ���� �÷� ������.
		for (int j = 1; j < i; j++) {
			// ���� �����̱⿡ A[j]<A[i]�̸鼭
			// ������ ���� �� ū ���� ���� upD1ate�Ѵ�.
			if (A2[j]<A2[i] && D2[j] + 1 > D2[i])
				D2[i] = D2[j] + 1;
		}
	}

	vector<int> D_2;

	D_2.push_back(0);

	for (int i = N; i >= 1; i--)
		D_2.push_back(D2[i]);

	delete[] D2;

	int * DP = new int[N + 1];

	for (int i = 1; i <= N; i++)
		DP[i] = D1[i] + D_2[i] - 1;

	int max = DP[1];

	for (int i = 2; i <= N; i++)
		if (DP[i] > max)
			max = DP[i];

	cout << max << endl;

	return 0;
}