#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *D = new int[N + 1];
	int *A = new int[N + 1];

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	// ���� ���� ������ �ڸ��� �ظ� �̸� �ִ´�.
	D[1] = 1;

	// �ظ� ä�� ������.
	for (int i = 2; i <= N; i++) {
		// �� �ε����� ���� �ش� �ڱ� �ڽ��� 1�̶�� �����Ѵ�.
		D[i] = 1;


		// ���� �÷� ������.
		for (int j = 1; j < i; j++) {
			// ���� �����̱⿡ A[j]<A[i]�̸鼭
			// ������ ���� �� ū ���� ���� update�Ѵ�.
			if (A[j]<A[i] && D[j] + 1 > D[i])
				D[i] = D[j] + 1;
		}
	}

	/*
		���� �۾����� �迭 D�� ������ ��� ä������, ���⼭ �ִ��� ã��!
	*/

	// �켱 �ִ��� ù° ���Ҷ�� ��������.
	int max = D[1];

	for (int i = 2; i <= N; i++)
		if (D[i] > max)
			max = D[i];

	cout << max << endl;

	return 0;
}