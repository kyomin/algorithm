#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;

	int len1 = s1.size();
	int len2 = s2.size();

	int **DP = new int*[len1];

	for (int i = 0; i < len1; i++)
		DP[i] = new int[len2];

	for (int i = 0; i < len1; i++)
		for (int j = 0; j < len2; j++)
			DP[i][j] = 0;
		
	int max = 0;

	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (s1[i] == s2[j])
				if (i == 0 || j == 0)
					DP[i][j] = 1;
				else
					DP[i][j] = DP[i - 1][j - 1] + 1;

			if (max < DP[i][j])
				max = DP[i][j];
		}
	}

	cout << max << endl;

	return 0;
}