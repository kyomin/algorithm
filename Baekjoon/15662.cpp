#include <iostream>
#include <string>

using namespace std;

char CLOCKS[1000][8];
int K, T;

// ȸ����Ű�� �Լ�
void rotation(int target, int direction, int status) {
	// ó�� ���� �ð���
	if (status == 0) {
		// ������ �� �˻��Ѵ�.

		// ������ �ð谡 �ְ�
		if (target + 1 < T) {
			// �ٸ� ���̶��
			if (CLOCKS[target][2] != CLOCKS[target + 1][6])
				// �굵 ȸ�� ���
				rotation(target + 1, direction*(-1), 2);
		}

		// ���� �ð谡 �ְ�
		if (target - 1 >= 0) {
			// �ٸ� ���̶��
			if (CLOCKS[target][6] != CLOCKS[target - 1][2]) 
				// �굵 ȸ�� ���
				rotation(target - 1, direction*(-1), 1);
		}
	}
	// �������� ������� �ð���
	else if (status == 1) {
		// ���� �ð谡 �ְ�
		if (target - 1 >= 0) {
			// �ٸ� ���̶��
			if (CLOCKS[target][6] != CLOCKS[target - 1][2])
				// �굵 ȸ�� ���
				rotation(target - 1, direction*(-1), 1);
		}
	}
	else {
		// ������ �ð谡 �ְ�
		if (target + 1 < T) {
			// �ٸ� ���̶��
			if (CLOCKS[target][2] != CLOCKS[target + 1][6])
				// �굵 ȸ�� ���
				rotation(target + 1, direction*(-1), 2);
		}
	}

	// �ڱ� �� ȸ��!
	char temp[8];

	// �ð����
	if (direction == 1) {
		for (int i = 0; i < 8; i++) {
			if (i == 0) {
				temp[i] = CLOCKS[target][7];
				continue;
			}

			temp[i] = CLOCKS[target][i - 1];
		}
	}
	// �ݽð����
	else {
		for (int i = 7; i >= 0; i--) {
			if (i == 7) {
				temp[i] = CLOCKS[target][0];
				continue;
			}

			temp[i] = CLOCKS[target][i + 1];
		}
	}

	// �� ����!
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
		// a : Ÿ�� �ð�, b : ����
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