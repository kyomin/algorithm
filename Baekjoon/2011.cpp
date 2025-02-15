#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int len = str.size();
	int *DP = new int[len + 1];

	// �ϴ� ��� 0���� �ʱ�ȭ!
	for (int i = 0; i <= len; i++)
		DP[i] = 0;

	DP[0] = 1;

	for (int i = 1; i <= len; i++) {
		// ���� ���ڸ� ������ �ٲ۴�.
		int x = str[i - 1] - '0';

		if (x >= 1 && x <= 9)
			DP[i] = (DP[i] + DP[i - 1]) % 1000000;

		// ������ 1�ڸ� ��ȣ�� ���ؼ� ó���Ͽ���.
		// ������ 2�ڸ� ��ȣ�� ���� ó������.

		// ���ʿ� ���̰� 1�̸� �ش���� x
		if (i == 1)
			continue;
		else if (str[i - 2] == '0')
			continue;

		x = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');

		if (10 <= x && x <= 26)
			DP[i] = (DP[i] + DP[i - 2]) % 1000000;
	}

	cout << DP[len] % 1000000 << '\n';

	return 0;
}