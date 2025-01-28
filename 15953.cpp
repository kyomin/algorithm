#include <iostream>
using namespace std;

int getFirstPrize(int rank) {
	if (rank == 0)
		return 0;

	if (rank == 1) {
		return 5000000;
	}
	else if (rank > 1 && rank <= 3) {
		return 3000000;
	}
	else if (rank > 3 && rank <= 6) {
		return 2000000;
	}
	else if (rank > 6 && rank <= 10) {
		return 500000;
	}
	else if (rank > 10 && rank <= 15) {
		return 300000;
	}
	else if (rank > 15 && rank <= 21) {
		return 100000;
	}

	return 0;
}

int getSecondPrize(int rank) {
	if (rank == 0)
		return 0;

	if (rank == 1) {
		return 5120000;
	}
	else if (rank > 1 && rank <= 3) {
		return 2560000;
	}
	else if (rank > 3 && rank <= 7) {
		return 1280000;
	}
	else if (rank > 7 && rank <= 15) {
		return 640000;
	}
	else if (rank > 15 && rank <= 31) {
		return 320000;
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int first, second;
		cin >> first >> second;

		cout << getFirstPrize(first) + getSecondPrize(second) << '\n';
	}

	return 0;
}