#include <iostream>
#include <cstring>

using namespace std;

int cows[101];
int N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	memset(cows, -1, sizeof(cows));
	
	cin >> N;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int cow, line;
		cin >> cow >> line;

		if (cows[cow] == -1) {
			cows[cow] = line;
		}
		else {
			if (cows[cow] != line) {
				ans++;
				cows[cow] = line;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}