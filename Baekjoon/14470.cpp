#include <iostream>

using namespace std;

int main() {
	int ans = 0;
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;

	// ���϶��
	if (A < 0) {
		// ���������� ��ǥ �µ��� ���϶��
		if (B <= 0) {
			int diff = B - A;
			ans += (diff*C);
		}
		// ��ǥ �µ��� ����̶��
		else {
			// �ϴ� 0������ �ø���.
			ans += (((-1)*A)*C);
			A = 0;

			// 0���� ��� �ص�
			ans += D;

			ans += B * E;
		}
	}
	// ����̶��(A�� 0�� ���� �Է����� �־����� �ʴ´�)
	else {
		ans += (B-A) * E;
	}

	cout << ans << '\n';

	return 0;
}