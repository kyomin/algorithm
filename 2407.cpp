#include <iostream>

using namespace std;

unsigned long long countFactorial(int N, int cnt) {
	if (cnt == 1)
		return N;

	return N * countFactorial(N - 1, cnt - 1);
}

int main() {
	int n, m;
	cin >> n >> m;

	cout << countFactorial(n, m) / countFactorial(m, m) << '\n';

	return 0;
}