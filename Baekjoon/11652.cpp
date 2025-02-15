#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	long long * A = new long long[N];

	for (int i = 0; i < N; i++) {
		long long n;
		cin >> n;
		A[i] = n;
	}

	sort(A, A + N);

	long long cnt = 1;
	long long num = A[0];
	long long ans = 1;

	for (int i = 1; i < N; i++) {
		if (A[i] != A[i - 1]) {
			if (ans < cnt) {
				ans = cnt;
				num = A[i - 1];
			}

			cnt = 1;
		}
		else
			cnt += 1;
	}

	if (cnt > ans) {
		ans = cnt;
		num = A[N - 1];
	}

	cout << num << endl;

	return 0;
}