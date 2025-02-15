#include <iostream>

using namespace std;

bool solution(int N) {
	int result = 0;
	int tempN = N;

	while (N != 0) {
		result += (N % 10);
		N /= 10;
	}

	if (tempN%result == 0)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int result = 0;

	for (int n = 1; n <= N; n++)
		if (solution(n))
			result++;

	cout << result << endl;

	return 0;
}