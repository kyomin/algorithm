#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	vector<int> result;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		int *D = new int[N + 1];

		// 가장 작은 문제의 자명한 해는 미리 저장한다!
		D[1] = 1;
		D[2] = 2;
		D[3] = 4;

		if (N == 1 || N == 2 || N == 3)
			result.push_back(D[N]);
		else {
			for (int j = 4; j <= N; j++)
				D[j] = D[j - 1] + D[j - 2] + D[j - 3];

			result.push_back(D[N]);
		}

		// 작업이 완료되면 해제!
		delete[] D;
	}

	int len = result.size();

	for (int i = 0; i < len; i++)
		cout << result[i] << endl;

	return 0;
}