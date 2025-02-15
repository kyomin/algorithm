#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *D1 = new int[N + 1];
	int *A1 = new int[N + 1];

	for (int i = 1; i <= N; i++)
		cin >> A1[i];

	// 가장 작은 문제의 자명한 해를 미리 넣는다.
	D1[1] = 1;

	// 해를 채워 나간다.
	for (int i = 2; i <= N; i++) {
		// 각 인덱스의 최초 해는 자기 자신인 1이라고 가정한다.
		D1[i] = 1;

		// 점점 늘려 나간다.
		for (int j = 1; j < i; j++) {
			// 증가 수열이기에 A[j]<A[i]이면서
			// 갱신을 위해 더 큰 값이 오면 upD1ate한다.
			if (A1[j]<A1[i] && D1[j] + 1 > D1[i])
				D1[i] = D1[j] + 1;
		}
	}

	/*
		위의 작업으로 배열 D1의 내용이 모두 채워졌다.
		다음으로 감소하는 부분수열의 해를 담기 위한 D2의 내용을 채워보자.
	*/

	// 감소하는 부분수열의 해를 담기 위한 배열 여기서는 해당 i값을 시작으로 했을 때, 가장 긴 것을 나타낼 것이다.
	int *D2 = new int[N + 1];

	// 위의 배열의 값을 거꾸로 담기 위한 배열
	vector<int> A2;

	// 0 인덱스에 쓰레기 값 담기!
	A2.push_back(0);

	for (int i = N; i >= 1; i--)
		A2.push_back(A1[i]);

	D2[1] = 1;

	for (int i = 2; i <= N; i++) {
		// 각 인덱스의 최초 해는 자기 자신인 1이라고 가정한다.
		D2[i] = 1;

		// 점점 늘려 나간다.
		for (int j = 1; j < i; j++) {
			// 증가 수열이기에 A[j]<A[i]이면서
			// 갱신을 위해 더 큰 값이 오면 upD1ate한다.
			if (A2[j]<A2[i] && D2[j] + 1 > D2[i])
				D2[i] = D2[j] + 1;
		}
	}

	vector<int> D_2;

	D_2.push_back(0);

	for (int i = N; i >= 1; i--)
		D_2.push_back(D2[i]);

	delete[] D2;

	int * DP = new int[N + 1];

	for (int i = 1; i <= N; i++)
		DP[i] = D1[i] + D_2[i] - 1;

	int max = DP[1];

	for (int i = 2; i <= N; i++)
		if (DP[i] > max)
			max = DP[i];

	cout << max << endl;

	return 0;
}