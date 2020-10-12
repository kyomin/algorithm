#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	// 2차원 배열 동적할당하는 과정!
	unsigned long **D = new unsigned long*[N + 1];

	for (int i = 0; i <= N; i++)
		D[i] = new unsigned long[2];

	// 가장 작은 부분의 자명한 해를 먼저 넣는다.
	D[1][0] = 0;
	D[1][1] = 1;

	// 2째 행부터 N번째까지!
	for (int i = 2; i <= N; i++) {
		/*
			i자리의 이친수의 개수 중에서 0 또는 1로 끝나는 것의 개수를 구한다!
		*/

		// 끝이 0으로 끝난다면 그 이전의 수는 0과 1 모두를 가지므로 아래의 공식이,
		D[i][0] = D[i - 1][0] + D[i - 1][1];

		// 끝이 1로 끝난다면 그 이전의 수는 0만 올 수 있으므로 아래의 공식이 나온다.
		D[i][1] = D[i - 1][0];
	}

	// 구하고자 하는 최종 결과는 2가지 경우를 나눈 것들의 합이다.
	unsigned long result = D[N][0] + D[N][1];

	// 동적할당한 메모리를 해제한다.
	for (int i = 0; i <= N; i++)
		delete[] D[i];

	delete[] D;

	// 출력!
	cout << result << endl;

	return 0;
}