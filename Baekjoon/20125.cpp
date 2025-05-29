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

	int leftArm = 0;	// ���� ��
	int rightArm = 0;	// ������ ��
	int back = 0;		// �㸮
	int leftLeg = 0;	// ���� �ٸ�
	int rightLeg = 0;	// ������ �ٸ�

	// ���� ��ǥ
	int chestR = 0;
	int chestC = 0;

	// ��� ��ǥ
	int pelvisR = 0;
	int pelvisC = 0;

	// ���� ��ǥ�� ã�´�.
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

	// ���� �� ���̸� ���Ѵ�.
	for (int c = chestC - 1; c >= 0; c--) {
		if (map[chestR][c] == '*') {
			leftArm++;
		}
		else {
			break;
		}
	}

	// ������ �� ���̸� ���Ѵ�.
	for (int c = chestC + 1; c < C; c++) {
		if (map[chestR][c] == '*') {
			rightArm++;
		}
		else {
			break;
		}
	}

	// �㸮 ���̸� ���Ѵ�.
	for (int r = chestR + 1; r < R; r++) {
		if (map[r][chestC] == '*') {
			back++;
		}
		else {
			// ��ݿ� ������ ���̽��̴�.
			pelvisR = r;
			pelvisC = chestC;

			break;
		}
	}

	// ���� �ٸ� ���̸� ���Ѵ�.
	for (int r = pelvisR; r < R; r++) {
		for (int c = pelvisC; c >= 0; c--) {
			if (map[r][c] == '*') {
				leftLeg++;
			}
		}
	}

	// ������ �ٸ� ���̸� ���Ѵ�.
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