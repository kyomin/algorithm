#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *D = new int[N + 1];
	int *A = new int[N + 1];

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	// 가장 작은 문제의 자명한 해를 미리 넣는다.
	D[1] = 1;

	// 해를 채워 나간다.
	for (int i = 2; i <= N; i++) {
		// 각 인덱스의 최초 해는 자기 자신인 1이라고 가정한다.
		D[i] = 1;


		// 점점 늘려 나간다.
		for (int j = 1; j < i; j++) {
			// 증가 수열이기에 A[j]<A[i]이면서
			// 갱신을 위해 더 큰 값이 오면 update한다.
			if (A[j]<A[i] && D[j] + 1 > D[i])
				D[i] = D[j] + 1;
		}
	}

	/*
		위의 작업으로 배열 D의 내용이 모두 채워졌고, 여기서 최댓값을 찾자!
	*/

	// 우선 최댓값을 첫째 원소라고 가정하자.
	int max = D[1];

	for (int i = 2; i <= N; i++)
		if (D[i] > max)
			max = D[i];

	cout << max << endl;

	return 0;
}