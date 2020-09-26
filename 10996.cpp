#include <iostream>

using namespace std;

void printStars(int N) {
	int up = (N / 2) + (N % 2);
	int down = (N / 2);

	for (int i = 0; i < up; i++) {
		cout << "* ";
	}

	cout << endl;

	for (int i = 0; i < down; i++) {
		cout << " *";
	}

	cout << endl;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		printStars(N);
	}

	return 0;
}