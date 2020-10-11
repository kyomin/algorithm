#include <iostream>
#include <string>

using namespace std;

int dp[101][101][101];
char table1[101];		
char table2[101];		
char table3[101];

int max3(int a, int b, int c) {
	if (a > b) {
		return (a > c) ? a : c;
	}
	else {
		return (b > c) ? b : c;
	}
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;

	int len1 = str1.size();
	int len2 = str2.size();
	int len3 = str3.size();

	for (int i = 0; i < len1; i++)
		table1[i + 1] = str1[i];

	for (int i = 0; i < len2; i++)
		table2[i + 1] = str2[i];

	for (int i = 0; i < len3; i++)
		table3[i + 1] = str3[i];

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			for (int k = 1; k <= len3; k++) {
				if (table1[i] == table2[j] && table2[j] == table3[k])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max(
						max3(dp[i - 1][j - 1][k],
							dp[i - 1][j][k - 1],
							dp[i][j - 1][k - 1]),

						max3(dp[i - 1][j][k],
							dp[i][j - 1][k],
							dp[i][j][k - 1])
					);
			}
		}
	}

	cout << dp[len1][len2][len3] << '\n';

	return 0;
}