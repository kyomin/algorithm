#include <iostream>
#include <algorithm>

using namespace std;

// N�� ������ �ִ� ������ �������� ��´�
int D[1500002];

// �ɸ��� �Ⱓ
int T[1500001];

// �ݾ�
int P[1500001];

int N;

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];

		D[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			// �ϴ� ���
			D[i + T[i]] = max(D[i + T[i]], D[i] + P[i]);

			// �� �ϴ� ���
			D[i + 1] = max(D[i + 1], D[i]);
		}
		else if (i + T[i] > N + 1)
			// �� ���� �׻� ����� �� �� ���� ����̴�.
			D[i + 1] = max(D[i + 1], D[i]);
	}

	cout << D[N + 1] << '\n';

	return 0;
}