#include <iostream>

using namespace std;

int main() {
	// 300 -> 60 -> 10 ������ ��ư�� �ִ��� ������ �ּҰ� �� ���̴�
	int A, B, C;
	int T;
	cin >> T;

	// 10���� ���� �������� ������ �ذ� ���Ѵ�
	if (T % 10 != 0)
		cout << -1 << '\n';
	else {
		A = T / 300;
		T %= 300;

		B = T / 60;
		T %= 60;

		C = T / 10;
		T %= 10;

		cout << A << ' ' << B << ' ' << C << '\n';
	}

	return 0;
}