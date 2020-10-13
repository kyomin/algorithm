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

		int min = N - 2; // ���̸� �ϴ� ���� ū ������ ��´�.
		int a, b;

		for (int i = 2; i < N; i++) {
			// i�� �Ҽ��̰� N-i�� �Ҽ���� �ظ� ���� ���̴�.
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