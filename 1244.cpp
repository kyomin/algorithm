#include <iostream>
using namespace std;

int N, K, a[101];

// 남학생의 동작
void sol1(int n) {
	for (int i = n; i <= N; i += n)
		a[i] = 1 - a[i];
}

// 여학생의 동작
void sol2(int n) {
	int k = 0;
	for (int i = 1; i <= N / 2; i++) {
		if (n - i < 1 || n + i > N || a[n - i] != a[n + i])
			break;
		k = i;
	}

	for (int i = n - k; i <= n + k; i++)
		a[i] = 1 - a[i];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	cin >> K;

	while (K--) {
		int p, m;
		cin >> p >> m;

		if (p == 1)
			sol1(m);
		else
			sol2(m);
	}

	for (int i = 1; i <= N; i++) {
		cout << a[i] << ' ';
		if (i % 20 == 0)
			cout << endl;
	}

	return 0;
}