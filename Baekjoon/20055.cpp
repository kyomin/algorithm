#include <iostream>
#include <utility>
using namespace std;

int beltArr[201] = { 0 };
pair<int, bool> isRobot[101];
int N, K;

bool cntZero() {
	int cnt = 0;
	bool res = false;
	for (int i = 1; i <= 2 * N; i++) {
		if (beltArr[i] == 0) {
			cnt++;
		}
		if (cnt >= K) {
			res = true;
			break;
		}
	}

	return res;
}

int findFirstRobot() {
	for (int i = N; i >= 1; i--) {
		if (isRobot[i].second == true) {
			return i;
		}
	}

	return 0;
}

void shiftRobot() {
	int minIdx = findFirstRobot();

	if (minIdx != 0) {
		for (int i = minIdx; i >= 1; i--) {
			if (isRobot[i].second == true) {
				if (i == N) {
					isRobot[i].first = 0;
					isRobot[i].second = false;
				}
				else {
					if (isRobot[i + 1].second == false && beltArr[i + 1] >= 1) {
						isRobot[i + 1] = isRobot[i];
						beltArr[i + 1] -= 1;
						isRobot[i].first = 0;
						isRobot[i].second = false;
					}
				}
			}
		}
	}
}

void shiftNumber() {
	int tmp = beltArr[2 * N];
	
	for (int i = 2 * N - 1; i >= 1; i--) {
		beltArr[i + 1] = beltArr[i];
	}

	beltArr[1] = tmp;
	isRobot[N].first = 0;
	isRobot[N].second = false;

	for (int i = N - 1; i >= 1; i--) {
		isRobot[i + 1] = isRobot[i];
	}

	isRobot[1].first = 0;
	isRobot[1].second = false;
}

bool putRobot(int order) {
	if (beltArr[1] >= 1 && isRobot[1].second == false) {
		beltArr[1] -= 1;
		isRobot[1].first = order;
		isRobot[1].second = true;

		return true;
	}

	return false;
}

int solution() {
	int ord = 1;
	int step = 1;
	
	while (1) {
		shiftNumber();
		
		if (cntZero())
			break;

		shiftRobot();

		if (cntZero())
			break;

		if (putRobot(ord))
			ord++;		

		if (cntZero())
			break;

		step += 1;
	}

	return step;
}

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> beltArr[i];
		isRobot[i].first = 0;
		isRobot[i].second = false;
	}

	for (int i = N + 1; i <= 2 * N; i++) {
		cin >> beltArr[i];
	}

	cout << solution();

	return 0;
}