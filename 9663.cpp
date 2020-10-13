#include <iostream>

using namespace std;

int N;
int col[15];
int result = 0;

bool promising(int i) {
	for (int j = 0; j < i; j++)
		/*
			���ο� ���� ������ ���� ���� '��'�� �ְų�
			�밢���� ���� ���
		*/
		if (col[i] == col[j] || abs(col[i] - col[j]) == (i - j))
			return false;	// ���� �� ����

	return true;
}

void N_Queen(int i) {
	if (i == N)	// ü���� ���� �������ٸ�
		result += 1;
	else {
		for (int j = 0; j < N; j++) {
			col[i] = j;	// ���� ���� jĭ�� ���ƺ���.

			// i���� j���� ���� ���� �����ٸ�
			if (promising(i))
				// �������� ����
				N_Queen(i + 1);
		}
	}
}

int main() {
	cin >> N;

	N_Queen(0);

	cout << result << endl;

	return 0;
}