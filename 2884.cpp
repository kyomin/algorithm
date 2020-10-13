#include <iostream>

using namespace std;

int main() {
	int H, M;
	cin >> H >> M;

	int judge = M - 45;

	if (judge < 0) {
		judge *= (-1);
		M = 60 - judge;
		H -= 1;

		if (H < 0)
			H = 23;

		cout << H << ' ' << M << endl;
	}
	else
		cout << H << ' ' << M - 45 << endl;

	return 0;
}