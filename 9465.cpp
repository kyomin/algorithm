#include <iostream>
#include <algorithm>	// min, max함수를 위함!
#include <vector>

using namespace std;

int main() {
	int N, T;
	vector<int> v;

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		// N열의 해당 상태(0, 1, 2)에서의 누적된 최댓값을 담기 위한 배열
		int **D = new int*[N + 1];

		for (int i = 0; i <= N; i++)
			D[i] = new int[3];

		// 실제 스티거의 점수들을 담기 위한 2차원 배열
		int **A = new int*[3];

		for (int i = 0; i < 3; i++) 
			A[i] = new int[N + 1];

		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= N; j++)
				cin >> A[i][j];

		// 가장 작은 문제의 자명한 해는 미리 담는다.
		D[1][0] = 0;
		D[1][1] = A[1][1];
		D[1][2] = A[2][1];

		for (int i = 2; i <= N; i++) {
			D[i][0] = max(max(D[i - 1][0], D[i - 1][1]), D[i - 1][2]);
			D[i][1] = max(D[i - 1][0], D[i - 1][2]) + A[1][i];
			D[i][2] = max(D[i - 1][0], D[i - 1][1]) + A[2][i];
		}

		v.push_back(max(max(D[N][0], D[N][1]), D[N][2]));
	}

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i] << '\n';

	return 0;
}