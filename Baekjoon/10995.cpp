#include <iostream>

using namespace std;

void printStars(int N) {
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1)
			for (int j = 0; j < N; j++)
				cout << "* ";
		else
			for (int j = 0; j < N; j++)
				cout << " *";

		cout << endl;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N; 
	cin >> N;

	printStars(N);

	return 0;
}