#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ans = 0;
int N;
string originalMap[50];
string copyMap[50];

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

void setCopyMap() {
	for (int r = 0; r < N; r++)
		copyMap[r] = originalMap[r];
}

void coundMaxCandyNum() {
	// 가로 세기
	for (int r = 0; r < N; r++) {
		int cnt = 1;
		char curCandy = copyMap[r][0];

		for (int c = 1; c < N; c++) {
			if (copyMap[r][c] == curCandy) {
				cnt++;
				continue;
			}

			ans = max(ans, cnt);
			curCandy = copyMap[r][c];
			cnt = 1;
		}

		ans = max(ans, cnt);
	}

	// 세로 세기
	for (int c = 0; c < N; c++) {
		int cnt = 1;
		char curCandy = copyMap[0][c];

		for (int r = 1; r < N; r++) {
			if (copyMap[r][c] == curCandy) {
				cnt++;
				continue;
			}

			ans = max(ans, cnt);
			curCandy = copyMap[r][c];
			cnt = 1;
		}

		ans = max(ans, cnt);
	}
}

int main() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		cin >> originalMap[r];
		copyMap[r] = originalMap[r];
	}

	// 우선 처음 상태에서 사탕 개수를 센다.
	coundMaxCandyNum();

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int nextR = r + 1;
			int nextC = c + 1;

			setCopyMap();
			if (isInside(r, nextC)) {
				// swap
				int tmp = copyMap[r][c];
				copyMap[r][c] = copyMap[r][nextC];
				copyMap[r][nextC] = tmp;

				coundMaxCandyNum();
			}

			setCopyMap();
			if (isInside(nextR, c)) {
				setCopyMap();

				// swap
				int tmp = copyMap[r][c];
				copyMap[r][c] = copyMap[nextR][c];
				copyMap[nextR][c] = tmp;

				coundMaxCandyNum();
			}
		}
	}

	cout << ans << endl;

	return 0;
}