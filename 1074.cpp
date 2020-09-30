#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, r, c;
	cin >> n >> r >> c;

	int ans = 0;

	// �߾� ���� ��ǥ ���ϱ�
	int row_mid = (int)pow(2, n) / 2;
	int col_mid = row_mid;

	while (n-- > 0) {
		int temp = (int)pow(2, n) / 2;
		int skip = (int)pow(4, n);		// �� ��и��� �ǳʶٴ� ����

		// 1��и�
		if (r < row_mid && c < col_mid) {
			// �߾� ��ǥ �̵�
			col_mid -= temp;
			row_mid -= temp;
		}
		else if (r < row_mid && col_mid <= c) {
			// 2��и�
			col_mid += temp;
			row_mid -= temp;
			ans += skip;
		}
		else if (row_mid <= r && c < col_mid) {
			// 3��и�
			col_mid -= temp;
			row_mid += temp;
			ans += skip * 2;
		}
		else {
			// 4��и�
			col_mid += temp;
			row_mid += temp;
			ans += skip * 3;
		}
	}

	cout << ans << '\n';
	
	return 0;
}