#include <iostream>
#include <cstring>

using namespace std;

bool D[31][31][31][436];
char ans[32];

// n : ���ڿ� ����, k : ������ ���� ����
int n, k;

bool go(int i, int a, int b, int p) {
	if (i == n) {
		if (p == k)
			return true;
		else
			return false;
	}

	if (D[i][a][b][p])
		return false;

	D[i][a][b][p] = true;

	ans[i] = 'A';
	if (go(i + 1, a + 1, b, p))
		return true;

	ans[i] = 'B';
	if (go(i + 1, a, b + 1, p + a))
		return true;

	ans[i] = 'C';
	if (go(i + 1, a, b, p + a + b))
		return true;

	// ��� ���ڿ��� ����� ���������� �� ã����
	return false;
}

int main() {
	cin >> n >> k;

	if (go(0, 0, 0, 0))
		cout << ans << '\n';
	else
		cout << -1 << '\n';

	return 0;
}