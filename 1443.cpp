#include <iostream>

using namespace std;

int ans = 1;			// ó���� 1
int curOperCnt = 0;		// ���� Ƚ��
bool foundAns = false;	// ���� ã�Ҵ°�?
int D, P;

// �ڸ��� ���
int calcDigits(int num) {
	int result = 0;

	while (num != 0) {
		num /= 10;
		result++;
	}

	return result;
}

void dfs() {
	// Pȸ�� ������ �ߴٸ�
	if (curOperCnt == P) {
		// ���� ����� D�ڸ��� �ѱ��� �ʴ´ٸ�
		if (calcDigits(ans) <= D) 
			foundAns = true;

		return;
	}

	for (int i = 9; i >= 2; i--) {
		ans *= i;
		curOperCnt++;

		dfs();

		if (foundAns)
			return;

		ans /= i;
		curOperCnt--;
	}
}

int main() {
	cin >> D >> P;

	dfs();

	if (foundAns) {
		cout << ans << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}