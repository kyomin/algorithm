#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 101;

int N, K;
int cache[MAX][MAX][2];		// N, K, 0 or 1

int numOfBits(int len, int total, int bit) {
	// 기저 사례
	if (len >= N || total > K)
		return 0;

	// 조건 충족
	if (len == N - 1 && total == K)
		return 1;

	// 메모제이션
	int &result = cache[len][total][bit];
	if (result != -1)
		return result;

	// 다음 비트는 0일 수도 1일 수도 있다.
	result = numOfBits(len + 1, total, 0) + numOfBits(len + 1, total + bit * 1, 1);

	return result;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		memset(cache, -1, sizeof(cache));
		cin >> N >> K;

		// s1 = 0 or 1
		cout << numOfBits(0, 0, 0) + numOfBits(0, 0, 1) << '\n';
	}

	return 0;
}