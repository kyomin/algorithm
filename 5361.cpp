#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		double A, B, C, D, E;
		cin >> A >> B >> C >> D >> E;

		double sum = (A* 350.34) + (B*230.90) + (C*190.55) + (D*125.30) + (E*180.90);
		cout << '$' << sum << endl;
	}

	return 0;
}