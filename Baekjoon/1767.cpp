#include <iostream>
#include <cstring>

using namespace std;

unsigned long long D[101][101][101];

unsigned long long go(int N, int M, int K) {
	if (K == 0)
		return 1;

	if (N <= 0 || M <= 0 || K < 0)
		return 0;

	unsigned long long &ans = D[N][M][K];

	if (ans != -1)
		return ans;

	ans = 0;

	/*
		1. N�� �࿡ ���� ���� �ʴ� ���
	*/
	ans += go(N - 1, M, K) % 1000001;

	/*
		2. N�� �࿡ ���� �ϳ� ���Ұ�,
		�ٸ� �迡�� ���ݹ��� �ʴ� ���
	*/
	ans += ((go(N - 1, M - 1, K - 1) % 1000001)*M) % 1000001;

	/*
		3. N�� �࿡ ���� �� �� ���� ���
	*/
	ans += ((go(N - 1, M - 2, K - 2) % 1000001)*((M*(M - 1)) / 2)) % 1000001;

	/*
		4. N�� �࿡ ���� �ϳ� ���Ұ�, �ٸ� �迡�� ���ݹ޴� ���
	*/
	ans += ((go(N - 2, M - 1, K - 2) % 1000001)*(M*(N - 1))) % 1000001;

	return ans % 1000001;
}

int main() {
	memset(D, -1, sizeof(D));

	int N, M, K;
	cin >> N >> M >> K;

	cout << go(N, M, K) % 1000001 << '\n';

	return 0;
}