#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> map;

	int R;
	cin >> R;

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;

		map.push_back(str);
	}

	int C = map[0].length();

	int leftArm = 0;	// 왼쪽 팔
	int rightArm = 0;	// 오른쪽 팔
	int back = 0;		// 허리
	int leftLeg = 0;	// 왼쪽 다리
	int rightLeg = 0;	// 오른쪽 다리

	// 가슴 좌표
	int chestR = 0;
	int chestC = 0;

	// 골반 좌표
	int pelvisR = 0;
	int pelvisC = 0;

	// 가슴 좌표를 찾는다.
	for (int r = 0; r < R; r++) {
		bool found = false;

		for (int c = 0; c < C; c++) {
			if (map[r][c] == '*') {
				chestR = r + 1;
				chestC = c;

				found = true;

				break;
			}
		}

		if (found)
			break;
	}

	// 왼쪽 팔 길이를 구한다.
	for (int c = chestC - 1; c >= 0; c--) {
		if (map[chestR][c] == '*') {
			leftArm++;
		}
		else {
			break;
		}
	}

	// 오른쪽 팔 길이를 구한다.
	for (int c = chestC + 1; c < C; c++) {
		if (map[chestR][c] == '*') {
			rightArm++;
		}
		else {
			break;
		}
	}

	// 허리 길이를 구한다.
	for (int r = chestR + 1; r < R; r++) {
		if (map[r][chestC] == '*') {
			back++;
		}
		else {
			// 골반에 도달한 케이스이다.
			pelvisR = r;
			pelvisC = chestC;

			break;
		}
	}

	// 왼쪽 다리 길이를 구한다.
	for (int r = pelvisR; r < R; r++) {
		for (int c = pelvisC; c >= 0; c--) {
			if (map[r][c] == '*') {
				leftLeg++;
			}
		}
	}

	// 오른쪽 다리 길이를 구한다.
	for (int r = pelvisR; r < R; r++) {
		for (int c = pelvisC; c < C; c++) {
			if (map[r][c] == '*') {
				rightLeg++;
			}
		}
	}
	
	cout << chestR + 1 << ' ' << chestC + 1 << endl;
	cout << leftArm << ' ' << rightArm << ' ' << back << ' ' << leftLeg << ' ' << rightLeg << endl;

	return 0;
}