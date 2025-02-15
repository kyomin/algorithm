#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		vector<int> A, B;
		int N, M;
		cin >> N >> M;

		A.resize(N);
		B.resize(M);

		for (int n = 0; n < N; n++)
			cin >> A[n];

		for (int m = 0; m < M; m++)
			cin >> B[m];

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int ans = 0;

		for (int i = 0; i < A.size(); i++) {
			int num = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
			ans += num;
		}

		cout << ans << '\n';
	}

	return 0;
}