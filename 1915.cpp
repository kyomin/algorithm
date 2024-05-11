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
	(r, c)�� ��ġ�� ������ �Ʒ� ���������� ���ϰ�,
	�ش� �ڸ����� �׸� �� �ִ� ���� ū ���簢���� ���� ����
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

	// ù ��° �� || ù ��° ���� ���ؼ��� �ٷ� DP �迭�� ä���
	for (int r = 0; r < R; r++)
		dp[r][0] = arr[r][0];

	for (int c = 0; c < C; c++)
		dp[0][c] = arr[0][c];

	// (2, 2) ��ġ���� DP �迭�� ä�� ������(�޸����̼�)
	for (int r = 1; r < R; r++) {
		for (int c = 1; c < C; c++) {
			if (arr[r][c] == 1)
				dp[r][c] = min(min(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1]) + 1;
			else
				dp[r][c] = 0;
		}
	}

	// ä���� DP �迭�κ��� �ִ��� ã�´�
	int ans = dp[0][0];

	for (const auto& row : dp)
		for (int val : row)
			ans = max(ans, val);

	// �ִ� ���簢���� �� ���� ���̷� ���������Ƿ� ���̸� ���� ������ ����Ѵ�
	cout << pow(ans, 2) << endl;

	return 0;
}