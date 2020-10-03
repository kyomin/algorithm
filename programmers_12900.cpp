#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	int *DP = new int[n + 1];

	DP[1] = 1;
	DP[2] = 2;

	if (n == 1 || n == 2) {
		answer = DP[n];
		return answer;
	}

	for (int i = 3; i <= n; i++)
		DP[i] = DP[i - 1] % 1000000007 + DP[i - 2] % 1000000007;

	answer = DP[n] % 1000000007;

	return answer;
}