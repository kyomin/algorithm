#include <iostream>

using namespace std;

int main() {
	int K, N;
	int curTime = 0, timeLimit = 210, curTarget;

	cin >> K >> N;

	curTarget = K;

	for (int n = 0; n < N; n++) {
		int T;
		char Z;

		cin >> T >> Z;

		if (curTime + T >= timeLimit)
			break;

		curTime += T;

		// 다음 사람에게 넘기는 경우
		if (Z == 'T') {
			if (curTarget == 8)
				curTarget = 1;
			else
				curTarget += 1;
		}
	}

	cout << curTarget << '\n';

	return 0;
}