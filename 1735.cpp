#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int temp1 = B, temp2 = D;

	/* 통분을 위한 작업 */

	// 분자
	int num1 = A * D + C * B;

	// 분모
	int num2 = B * D;

	int G = gcd(num1, num2);

	num1 /= G;
	num2 /= G;

	cout << num1 << ' ' << num2 << endl;

	return 0;
}