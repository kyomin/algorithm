#include <iostream>

using namespace std;

long long int calcPow(long long int a, long long int n, long long int  c) {
	if (n == 1)
		return a % c;
	else {
		long long int temp = calcPow(a, n / 2, c) % c;

		if (n % 2 == 0)
			return ((temp % c)*(temp % c)) % c;
		else
			return ((((temp % c) * (temp % c)) % c) * a%c) % c;
	}
}

int main() {
	long long int A, B, C;
	cin >> A >> B >> C;

	cout << calcPow(A, B, C) % C << endl;

	return 0;
}