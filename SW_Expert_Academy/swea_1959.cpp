#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;

		vector<int> A(N);
		vector<int> B(M);

		for (int i = 0; i < N; i++)
			cin >> A[i];

		for (int i = 0; i < M; i++)
			cin >> B[i];

		int ans = 0;

		if (M > N) {
			int end = M - N;

			// 우선 첫 번째 겹치는 구간
			for (int i = 0; i < N; i++)
				ans += (A[i] * B[i]);

			for (int i = 1; i <= end; i++) {
				int sum = 0;

				for (int j = i; j < i + N; j++) {
					sum += (A[j - i] * B[j]);
				}

				ans = max(ans, sum);
			}
		}
		else {
			int end = N - M;

			// 우선 첫 번째 겹치는 구간
			for (int i = 0; i < M; i++)
				ans += (A[i] * B[i]);

			for (int i = 1; i <= end; i++) {
				int sum = 0;

				for (int j = i; j < i + M; j++) {
					sum += (A[j] * B[j - i]);
				}

				ans = max(ans, sum);
			}
		}

		cout << '#' << t << ' ' << ans << endl;
	}

	return 0;
}