#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	// (N+1) X 10 2차원 배열 동적할당!
	unsigned long **D = new unsigned long*[N + 1];

	for (int i = 0; i <= N; i++)
		D[i] = new unsigned long[10];

	// 가장 작은 문제의 자명한 해는 먼저 입력한다!
	D[1][0] = 0;

	for (int i = 1; i <= 9; i++)
		D[1][i] = 1;

	// 본격적으로 bottom-up 하기!
	for (int i = 2; i <= N; i++) {
		// 처음(0)과 마지막(9)의 예외적인 부분은 그냥 넣는다.

		// 마지막에 오는 수가 0이라면 그 이전의 수는 1만이 오고,
		D[i][0] = D[i - 1][1] % (1000000000);

		// 마지막에 오는 수가 9라면 그 이전의 수는 8만이 올 수 있다.
		D[i][9] = D[i - 1][8] % (1000000000);

		// 마지막에 오는 수 j에 대해서 그 이전에 오는 수는 1 차이가 나야 하므로 j-1, j+1이다.
		// 이에 대해서의 문자열 길이는 i-1이다. 따라서 for문 안에서의 공식이 나온다.
		for (int j = 1; j <= 8; j++)
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % (1000000000);
	}

	// 큰 수를 담기 위하여 unsigned long형의 result 변수 선언!
	unsigned long result = 0;

	for (int i = 0; i <= 9; i++) 
		result += D[N][i];

	// 동적할당 해제!
	for (int i = 0; i <= N; i++)
		delete[] D[i];

	delete[] D;

	// 최종 결과에서 10억을 모듈러 연산 취한다!
	cout << result % (1000000000) << endl;

	return 0;
}