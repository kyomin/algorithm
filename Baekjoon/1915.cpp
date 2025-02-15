#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define MAX 1000
using namespace std;

int arr[MAX][MAX];

/*
	dp[r][c]
	=>
	(r, c)의 위치를 오른쪽 아래 꼭짓점으로 정하고,
	해당 자리에서 그릴 수 있는 가장 큰 정사각형의 변의 길이
*/
int dp[MAX][MAX];

int main() {
	int R, C;
	cin >> R >> C;

	for (int r = 0; r < R; r++) {
		string str;
		cin >> str;

		for (int c = 0; c < C; c++) {
			char ch = str[c];
			int num = (int)(ch - '0');

			arr[r][c] = num;
		}
	}

	// 첫 번째 행 || 첫 번째 열에 대해서는 바로 DP 배열을 채운다
	for (int r = 0; r < R; r++)
		dp[r][0] = arr[r][0];

	for (int c = 0; c < C; c++)
		dp[0][c] = arr[0][c];

	// (2, 2) 위치부터 DP 배열을 채워 나간다(메모제이션)
	for (int r = 1; r < R; r++) {
		for (int c = 1; c < C; c++) {
			if (arr[r][c] == 1)
				dp[r][c] = min(min(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1]) + 1;
			else
				dp[r][c] = 0;
		}
	}

	// 채워진 DP 배열로부터 최댓값을 찾는다
	int ans = dp[0][0];

	for (const auto& row : dp)
		for (int val : row)
			ans = max(ans, val);

	// 최대 정사각형의 한 변의 길이로 정의했으므로 넓이를 위해 제곱을 출력한다
	cout << pow(ans, 2) << endl;

	return 0;
}