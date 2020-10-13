#include <iostream>
#include <string>

using namespace std;

// 소수 판단 함수
bool prime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;

	return true;
}

int main() {
	int min;
	int sum = 0;
	int M, N;
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		if (prime(i)) {
			// 최초로 발견된 소수라면!
			if (sum == 0)
				min = i;

			sum += i;
		}
	}

	// 소수가 발견되지 않아 합이 0이라면
	if (sum == 0)
		cout << -1 << endl;
	else
	{
		cout << sum << endl;
		cout << min << endl;
	}

	return 0;
}