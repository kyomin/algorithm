#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	// 인덱스의 편의상 N+1개 할당!
	int *D = new int[N + 1];

	// 초기의 가장 작은 문제의 자명한 부분은 그 해를 채워 넣는다.
	D[0] = 1;
	D[1] = 1;

	// 바로 답이 나오는 경우이다.
	if (N == 1)
		cout << 1 % 10007 << endl;
	// 동적 규칙을 쫓아야 하는 부분이다.
	else {
		// 반복문을 돌며 N까지 채워 나간다.
		for (int i = 2; i <= N; i++)
			D[i] = (2 * D[i - 2] + D[i - 1]) % 10007;

		// 최종적으로 구한 값에 10007을 나눈 나머지를 출력한다.
		cout << D[N] << endl;
	}

	return 0;
}