#include <iostream>
using namespace std;

int A1[100][100];
int A2[100][100];
int A3[100][100];

int main() {
	int R1, C1;
	cin >> R1 >> C1;
	for (int r = 0; r < R1; r++)
		for (int c = 0; c < C1; c++)
			cin >> A1[r][c];

	int R2, C2;
	cin >> R2 >> C2;
	for (int r = 0; r < R2; r++)
		for (int c = 0; c < C2; c++)
			cin >> A2[r][c];

	for (int r1 = 0; r1 < R1; r1++) {
		for (int c = 0; c < C2; c++) {
			int sum = 0;

			for (int r2 = 0; r2 < R2; r2++)
				sum += (A1[r1][r2] * A2[r2][c]);
			

			A3[r1][c] = sum;			
		}
	}

	for (int r = 0; r < R1; r++) {
		for (int c = 0; c < C2 - 1; c++)
			cout << A3[r][c] << ' ';

		cout << A3[r][C2 - 1] << endl;
	}

	return 0;
}