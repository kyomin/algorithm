#include <iostream>
using namespace std;

char map[100][100];

int main() {
	int R, C, A, B;
	cin >> R >> C >> A >> B;

	R *= A;
	C *= B;
	
	int cnt = 1;
	for (int r = A; r <= R; r += A) {
		char color;
		if (cnt % 2 == 1)
			color = 'X';
		else
			color = '.';
		
		for (int c = B; c <= C; c += B) {
			for (int i = r - A; i < r; i++)
				for (int j = c - B; j < c; j++)
					map[i][j] = color;

			if(color == 'X')
				color = '.';
			else 
				color = 'X';
		}

		cnt++;
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++)
			cout << map[r][c];

		cout << endl;
	}

	return 0;
}