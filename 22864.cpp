#include <iostream>
using namespace std;

int main() {
	int A, B, C, M;
	cin >> A >> B >> C >> M;

	int T = 0;	// �Ƿε�
	int W = 0;	// �۾���

	for (int i = 0; i < 24; i++) {
		// ���ƿ�
		if (T > M) {
			W = 0;
			break;
		}

		// ���� �� �� �ִ� ���
		if (T + A <= M) {
			T += A;
			W += B;

			continue;
		}

		// ���� �� �� ���� ��� �޽�
		T = T - C >= 0 ? T - C : 0;
	}

	cout << W << endl;

	return 0;
}