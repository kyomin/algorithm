#include <iostream>

using namespace std;

int main() {
	int count = 0;	// �� ��°������ ǥ���ϱ� ���� ����
	int ans;	// ������ ��� ���� ����
	int N, K;
	cin >> N >> K;

	bool *C = new bool[N + 1];

	for (int i = 2; i <= N; i++)
		C[i] = false;

	for (int i = 2; i <= N; i++) {
		int judge = 0;

		for (int j = i * 1; j <= N; j += i) {
			// ���� �������� ���� �����
			if (C[j] == false) {
				C[j] = true;

				count += 1;

				if (count == K) {
					ans = j;
					judge = 1;

					break;
				}
			}
		}

		if (judge == 1)
			break;
	}

	cout << ans << endl;

	return 0;
}