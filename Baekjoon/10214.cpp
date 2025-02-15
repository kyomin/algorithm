#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int score_Y = 0;
		int score_K = 0;

		for (int i = 0; i < 9; i++) {
			int Y, K;
			cin >> Y >> K;

			score_Y += Y;
			score_K += K;
		}

		if (score_Y > score_K)
			cout << "Yonsei" << '\n';
		else if(score_Y < score_K)
			cout << "Korea" << '\n';
		else
			cout << "Draw" << '\n';
	}

	return 0;
}