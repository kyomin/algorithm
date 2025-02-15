#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, r, c;
	cin >> n >> r >> c;

	int ans = 0;

	// 중앙 기준 좌표 구하기
	int row_mid = (int)pow(2, n) / 2;
	int col_mid = row_mid;

	while (n-- > 0) {
		int temp = (int)pow(2, n) / 2;
		int skip = (int)pow(4, n);		// 한 사분면이 건너뛰는 개수

		// 1사분면
		if (r < row_mid && c < col_mid) {
			// 중앙 좌표 이동
			col_mid -= temp;
			row_mid -= temp;
		}
		else if (r < row_mid && col_mid <= c) {
			// 2사분면
			col_mid += temp;
			row_mid -= temp;
			ans += skip;
		}
		else if (row_mid <= r && c < col_mid) {
			// 3사분면
			col_mid -= temp;
			row_mid += temp;
			ans += skip * 2;
		}
		else {
			// 4사분면
			col_mid += temp;
			row_mid += temp;
			ans += skip * 3;
		}
	}

	cout << ans << '\n';
	
	return 0;
}