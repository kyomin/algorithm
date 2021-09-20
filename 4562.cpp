#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int X, Y;
		cin >> X >> Y;

		if (X < Y)
			cout << "NO BRAINS" << endl;
		else
			cout << "MMM BRAINS" << endl;
	}

	return 0;
}