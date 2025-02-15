#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	int D[100];

	for (int i = 0; i < 100; i++)
		D[i] = 0;

	cin >> A >> B >> C;

	// 3대 이므로!
	for (int i = 0; i < 3; i++) {
		int t1, t2;
		cin >> t1 >> t2;

		for (int j = t1; j < t2; j++)
			D[j] += 1;
	}

	int cost = 0;

	for (int i = 1; i < 100; i++) {
		if (D[i] == 1)
			cost += A;
		else if (D[i] == 2)
			cost += 2 * B;
		else if (D[i] == 3)
			cost += 3 * C;
	}

	cout << cost << endl;

	return 0;
}