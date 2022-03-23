#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int *A = new int[N];

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		A[i] = n;
	}

	int s = 0, e = 0, count = 0, sum = 0;
	while (true) {
		if (sum == M)
			count++;

		if (s == N && e == N)
			break;

		if (e == N || sum >= M) {
			sum -= A[s];
			s++;
		}
		else {
			sum += A[e];
			e++;
		}
	}

	cout << count << '\n';

	return 0;
}