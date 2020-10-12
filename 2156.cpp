#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int *A = new int[N + 1];

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	int **D = new int*[N + 1];

	for (int i = 1; i <= N; i++)
		D[i] = new int[2];

	// 가장 작은 문제의 자명한 해는 미리 채워 넣는다.
	D[1][0] = 0;
	D[1][1] = A[1];

	if (N >= 2) {
		D[2][0] = max(D[1][0], D[1][1]);
		D[2][1] = A[1] + A[2];
	}

	// 점화식을 적용하지 않는 경우는 다음의 처리를 한다.
	if (N == 1) {
		cout << A[1] << endl;
		return 0;	// 함수 종료!
	}
	else if (N == 2) {
		cout << max(D[2][0], D[2][1]) << endl;
		return 0;	// 함수 종료!
	}

	for (int i = 3; i <= N; i++) {
		D[i][0] = max(D[i - 1][0], D[i - 1][1]);
		D[i][1] = max(D[i - 2][0] + A[i - 1] + A[i],
			D[i - 1][0] + A[i]);
	}

	int result = max(D[N][0], D[N][1]);

	cout << result << '\n';

	return 0;
}