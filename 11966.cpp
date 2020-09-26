#include <iostream>

using namespace std;

int solution(unsigned int N) {
	if (N == 1)
		return 1;

	while (true) {
		if (N % 2 == 1)
			return 0;

		N /= 2;

		if (N == 1)
			break;
	}

	return 1;
}

int main() {
	int N;
	cin >> N;

	cout << solution(N) << '\n';

	return 0;
}