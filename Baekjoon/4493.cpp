#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int win1 = 0;
		int win2 = 0;
		int N;
		cin >> N;

		for (int n = 0; n < N; n++) {
			char p1, p2;
			cin >> p1 >> p2;

			// 비기지 않고 승부가 나는 경우
			if (p1 == 'R' && p2 == 'P')
				win2++;
			else if (p1 == 'R' && p2 == 'S')
				win1++;
			else if (p1 == 'S' && p2 == 'P')
				win1++;
			else if (p1 == 'S' && p2 == 'R')
				win2++;
			else if (p1 == 'P' && p2 == 'R')
				win1++;
			else if (p1 == 'P' && p2 == 'S')
				win2++;
		}

		if (win1 > win2)
			cout << "Player 1" << endl;
		else if (win1 < win2)
			cout << "Player 2" << endl;
		else
			cout << "TIE" << endl;
	}

	return 0;
}