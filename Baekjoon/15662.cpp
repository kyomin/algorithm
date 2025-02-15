#include <iostream>
#include <string>

using namespace std;

char CLOCKS[1000][8];
int K, T;

// 회전시키는 함수
void rotation(int target, int direction, int status) {
	// 처음 시작 시계라면
	if (status == 0) {
		// 양쪽을 다 검사한다.

		// 오른쪽 시계가 있고
		if (target + 1 < T) {
			// 다른 극이라면
			if (CLOCKS[target][2] != CLOCKS[target + 1][6])
				// 얘도 회전 대상
				rotation(target + 1, direction*(-1), 2);
		}

		// 왼쪽 시계가 있고
		if (target - 1 >= 0) {
			// 다른 극이라면
			if (CLOCKS[target][6] != CLOCKS[target - 1][2]) 
				// 얘도 회전 대상
				rotation(target - 1, direction*(-1), 1);
		}
	}
	// 왼쪽으로 뻗어나가는 시계라면
	else if (status == 1) {
		// 왼쪽 시계가 있고
		if (target - 1 >= 0) {
			// 다른 극이라면
			if (CLOCKS[target][6] != CLOCKS[target - 1][2])
				// 얘도 회전 대상
				rotation(target - 1, direction*(-1), 1);
		}
	}
	else {
		// 오른쪽 시계가 있고
		if (target + 1 < T) {
			// 다른 극이라면
			if (CLOCKS[target][2] != CLOCKS[target + 1][6])
				// 얘도 회전 대상
				rotation(target + 1, direction*(-1), 2);
		}
	}

	// 자기 것 회전!
	char temp[8];

	// 시계방향
	if (direction == 1) {
		for (int i = 0; i < 8; i++) {
			if (i == 0) {
				temp[i] = CLOCKS[target][7];
				continue;
			}

			temp[i] = CLOCKS[target][i - 1];
		}
	}
	// 반시계방향
	else {
		for (int i = 7; i >= 0; i--) {
			if (i == 7) {
				temp[i] = CLOCKS[target][0];
				continue;
			}

			temp[i] = CLOCKS[target][i + 1];
		}
	}

	// 값 복사!
	for (int i = 0; i < 8; i++)
		CLOCKS[target][i] = temp[i];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < 8; j++)
			CLOCKS[i][j] = str[j];
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		// a : 타겟 시계, b : 방향
		int a, b;
		cin >> a >> b;

		rotation(a - 1, b, 0);
	}

	int result = 0;

	for (int i = 0; i < T; i++)
		if (CLOCKS[i][0] == '1')
			result += 1;

	cout << result << '\n';

	return 0;
}