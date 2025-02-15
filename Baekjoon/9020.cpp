#include <iostream>
#include <vector>

using namespace std;

bool prime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;

	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	int T;
	cin >> T;

	for (int k = 0; k < T; k++) {
		int N;
		cin >> N;

		int min = N - 2; // 차이를 일단 가장 큰 것으로 잡는다.
		int a, b;

		for (int i = 2; i < N; i++) {
			// i가 소수이고 N-i도 소수라면 해를 구한 것이다.
			if (prime(i) && prime(N - i)) {
				if ((N - i) - i < min && (N - i) >= i) {
					min = (N - i) - i;
					a = i;
					b = (N - i);
				}
			}
		}

		v.push_back(a);
		v.push_back(b);
	}

	for (int i = 0; i < T; i++)
		cout << v[i * 2] << ' ' << v[i * 2 + 1] << '\n';

	return 0;
}