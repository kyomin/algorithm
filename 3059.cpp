#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool alphas[26];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		memset(alphas, false, sizeof(alphas));

		string S;
		cin >> S;

		int len = S.size();

		for (int i = 0; i < len; i++) {
			char alpha = S[i];

			alphas[(int)(alpha - 'A')] = true;
		}

		int sum = 0;

		for (int i = 0; i < 26; i++)
			if (!alphas[i])
				sum += (i + 65);

		cout << sum << '\n';
	}
}