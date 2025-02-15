#include <iostream>

using namespace std;

int main() {
	// 300 -> 60 -> 10 순으로 버튼을 최대한 눌러야 최소가 될 것이다
	int A, B, C;
	int T;
	cin >> T;

	// 10으로 나눠 떨어지지 않으면 해결 못한다
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