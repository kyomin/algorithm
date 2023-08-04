#include <iostream>
#include <cstring>
using namespace std;

char star[3072][6144];

void printStar(int x, int y, int n) {
	if (n == 3) {
		star[x][y] = '*';
		star[x + 1][y - 1] = '*';
		star[x + 2][y - 2] = '*';
		star[x + 2][y - 1] = '*';
		star[x + 2][y] = '*';
		star[x + 2][y + 1] = '*';
		star[x + 2][y + 2] = '*';
		star[x + 1][y + 1] = '*';
	}
	else {
		printStar(x, y, n / 2);
		printStar(x + n / 2, y - n / 2, n / 2);
		printStar(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	int N;
	cin >> N;
	
	memset(star, ' ', sizeof(star));

	printStar(0, N - 1, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++)
			cout << star[i][j];
		
		cout << '\n';
	}

	return 0;
}