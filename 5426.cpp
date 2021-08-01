#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;

		int len = str.length();
		int N = (int)sqrt(len);
		vector<string> a;

		for (int row = 0; row < N; row++) {
			string sub_str = "";

			for (int col = 0; col < N; col++) {
				int index = (row*N) + col;
				sub_str += str[index];
			}

			a.push_back(sub_str);
		}

		string ans = "";
		for (int col = N - 1; col >= 0; col--)
			for (int row = 0; row < N; row++)
				ans += a[row][col];
	
		cout << ans << '\n';
	}

	return 0;
}