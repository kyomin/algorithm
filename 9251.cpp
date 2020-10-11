#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];
char table1[1001];		// 비교 문자열 담기
char table2[1001];		// 기준 문자열 담기

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str1, str2;
	cin >> str1 >> str2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 0; i < len1; i++)
		table1[i + 1] = str1[i];

	for (int i = 0; i < len2; i++)
		table2[i + 1] = str2[i];

	for (int row = 1; row <= len1; row++) {
		for (int col = 1; col <= len2; col++) {
			if (table1[row] == table2[col])
				dp[row][col] = dp[row - 1][col - 1] + 1;
			else
				dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
		}
	}

	cout << dp[len1][len2] << '\n';

	return 0;
}