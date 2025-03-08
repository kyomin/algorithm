#include <iostream>
using namespace std;

int main() {
	int N = 5;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (row == col)
				cout << '#';
			else
				cout << '+';
		}

		cout << endl;
	}

	return 0;
}