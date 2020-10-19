#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int d[61][61][61];
int scv[3] = { 0, };
int N;

int go(int i, int j, int k) {
	if (i < 0) return go(0, j, k);
	if (j < 0) return go(i, 0, k);
	if (k < 0) return go(i, j, 0);

	// �� �̻� ������ Ƚ����  0�̴�(�ּ���)
	if (i == 0 && j == 0 && k == 0)
		return 0;

	int &ans = d[i][j][k];

	// �̹� ���� ������ �����
	if (ans != -1)
		return ans;

	ans = 1000000;

	vector<int> p = { 1, 3, 9 };

	do {
		ans = min(ans, go(i - p[0], j - p[1], k - p[2]));
	} while (next_permutation(p.begin(), p.end()));

	// ���� ���� Ƚ�� + ���� Ƚ��
	ans += 1;

	return ans;
}

int main() {
	cin >> N;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < N; i++)
		cin >> scv[i];

	cout << go(scv[0], scv[1], scv[2]) << '\n';

	return 0;
}