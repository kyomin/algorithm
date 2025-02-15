#include <iostream>

using namespace std;

void printStars(int N) {
	int up = (N / 2) + (N % 2);
	int down = (N / 2);

	for (int i = 0; i < up; i++)
		cout << "* ";

	cout << '\n';

	for (int i = 0; i < down; i++)
		cout << " *";

	cout << '\n';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		printStars(N);

	return 0;
}