#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char map[50][50];
char copyMap[50][50];

int ans = 0;
int N;

void setCopyMap(int row1, int col1, int row2, int col2) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copyMap[i][j] = map[i][j];
		}
	}

	int temp = map[row2][col2];

	copyMap[row2][col2] = map[row1][col1];
	copyMap[row1][col1] = temp;
}

// 1 : ���� ��ǥ, 2 : ���� ��ǥ�� �ٲ� ��ǥ
void swap(int row1, int col1, int row2, int col2, char dir) {
	// 0 : C, 1 : P, 2 : Z, 3 : Y
	int candyCount[4];

	// ��ȯ�� ����� copyMap ����
	setCopyMap(row1, col1, row2, col2);
	
	// ���������� ��ȯ�ߴٸ�
	if (dir == 'R') {
		memset(candyCount, 0, sizeof(candyCount));

		// ���� ���� ���캻��.
		for (int col = 0; col < N; col++) {
			if (copyMap[row1][col] == 'C') {
				candyCount[0]++;
			}
			else if (copyMap[row1][col] == 'P') {
				candyCount[1]++;
			}
			else if (copyMap[row1][col] == 'Z') {
				candyCount[2]++;
			}
			else {
				candyCount[3]++;
			}
		}

		int rowMax = *max_element(candyCount, candyCount + 4);

		// ���� ����
		ans = max(ans, rowMax);

		memset(candyCount, 0, sizeof(candyCount));

		// ���� �� 2���� ���캻��.
		for (int row = 0; row < N; row++) {
			if (copyMap[row][col1] == 'C') {
				candyCount[0]++;
			}
			else if (copyMap[row][col1] == 'P') {
				candyCount[1]++;
			}
			else if (copyMap[row][col1] == 'Z') {
				candyCount[2]++;
			}
			else {
				candyCount[3]++;
			}
		}

		int colMax = *max_element(candyCount, candyCount + 4);
		
		ans = max(ans, colMax);

		for (int row = 0; row < N; row++) {
			if (copyMap[row][col2] == 'C') {
				candyCount[0]++;
			}
			else if (copyMap[row][col2] == 'P') {
				candyCount[1]++;
			}
			else if (copyMap[row][col2] == 'Z') {
				candyCount[2]++;
			}
			else {
				candyCount[3]++;
			}
		}

		colMax = *max_element(candyCount, candyCount + 4);
		
		ans = max(ans, colMax);
	}
	else {		// �Ʒ������� ��ȯ�ߴٸ�
		memset(candyCount, 0, sizeof(candyCount));
				
		// ���� �� 2���� ���캻��.
		for (int col = 0; col < N; col++) {
			if (copyMap[row1][col] == 'C') {
				candyCount[0]++;
			}
			else if (copyMap[row1][col] == 'P') {
				candyCount[1]++;
			}
			else if (copyMap[row1][col] == 'Z') {
				candyCount[2]++;
			}
			else {
				candyCount[3]++;
			}
		}

		int rowMax = *max_element(candyCount, candyCount + 4);

		// ���� ����
		ans = max(ans, rowMax);

		for (int col = 0; col < N; col++) {
			if (copyMap[row2][col] == 'C') {
				candyCount[0]++;
			}
			else if (copyMap[row2][col] == 'P') {
				candyCount[1]++;
			}
			else if (copyMap[row2][col] == 'Z') {
				candyCount[2]++;
			}
			else {
				candyCount[3]++;
			}
		}

		rowMax = *max_element(candyCount, candyCount + 4);

		// ���� ����
		ans = max(ans, rowMax);

		// ���� ���� ���캻��.
		for (int row = 0; row < N; row++) {
			if (copyMap[row][col1] == 'C') {
				candyCount[0]++;
			}
			else if (copyMap[row][col1] == 'P') {
				candyCount[1]++;
			}
			else if (copyMap[row][col1] == 'Z') {
				candyCount[2]++;
			}
			else {
				candyCount[3]++;
			}
		}

		int colMax = *max_element(candyCount, candyCount + 4);
	
		// ���� ����
		ans = max(ans, colMax);
	}
}

int main() {
	cin >> N;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> map[row][col];
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			int right = col + 1;
			int bottom = row + 1;

			if (right < N && map[row][col] != map[row][right])
				swap(row, col, row, right, 'R');

			if(bottom < N && map[row][col] != map[bottom][col])
				swap(row, col, bottom, col, 'B');
		}
	}

	cout << ans << '\n';

	return 0;
}