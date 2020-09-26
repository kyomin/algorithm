#include <iostream>

using namespace std;

int scoreA = 0, scoreB = 0;
int resultA[10], resultB[10];
char winner[10];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 10; i++) {
		cin >> resultA[i];
	}

	for (int i = 0; i < 10; i++) {
		cin >> resultB[i];
	}

	for (int i = 0; i < 10; i++) {
		if (resultA[i] > resultB[i]) {
			scoreA += 3;
			winner[i] = 'A';
		}
		else if (resultA[i] < resultB[i]) {
			scoreB += 3;
			winner[i] = 'B';
		}
		else {
			scoreA += 1;
			scoreB += 1;
			winner[i] = 'D';
		}
	}

	cout << scoreA << ' ' << scoreB << '\n';

	if (scoreA > scoreB) {
		cout << 'A' << '\n';

		return 0;
	}
	else if (scoreA < scoreB) {
		cout << 'B' << '\n';

		return 0;
	}
	else {
		for (int i = 9; i >= 0; i--) {
			if (winner[i] != 'D') {
				cout << winner[i] << '\n';
			
				return 0;
			}
		}
	}

	cout << 'D' << '\n';

	return 0;
}