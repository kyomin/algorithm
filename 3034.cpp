#include <iostream>
#include <cmath>

using namespace std;

double calcDiagonal(double W, double H) {
	double diagonal = sqrt((W*W) + (H*H));

	return diagonal;
}

int main() {
	double N, W, H, diagonal;
	cin >> N >> W >> H;

	diagonal = calcDiagonal(W, H);

	for (int i = 0; i < N; i++) {
		double match;
		cin >> match;

		if (match <= W || match <= H || match <= diagonal) {
			cout << "DA" << '\n';
		}
		else {
			cout << "NE" << '\n';
		}
	}

	return 0;
}