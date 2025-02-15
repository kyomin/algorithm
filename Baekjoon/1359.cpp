#include <iostream>
using namespace std;

int fac(int num) {
	if (num <= 1) {
		return 1;
	}
	else {
		return num * fac(num - 1);
	}
}

int main() {
	int N;
	int M;
	int K;

	int denominator;
	int numerator;
	double result;

	cin >> N >> M >> K;

	denominator = fac(N) / (fac(M) * fac(N - M));
	numerator = 0;

	for (int i = K; i <= M; i++) {
		int jimin = fac(M) / (fac(i) * fac(M - i));
		int lotto = fac(N - M) / (fac(M - i) * fac(N - M - M + i));
		numerator += jimin * lotto;
	}

	result = double(numerator) / double(denominator);
	cout.precision(10);
	cout << result;

	return 0;
}