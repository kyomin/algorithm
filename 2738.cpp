#include <iostream>

using namespace std;

int A[101][101];
int B[101][101];
int result[101][101];

int main() {
	int N, M;
	cin >> N >> M;

	for (int row = 1; row <= N; row++)
		for (int col = 1; col <= M; col++)
			cin >> A[row][col];

	for (int row = 1; row <= N; row++)
		for (int col = 1; col <= M; col++)
			cin >> B[row][col];

	for (int row = 1; row <= N; row++)
		for (int col = 1; col <= M; col++)
			result[row][col] = A[row][col] + B[row][col];

	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= M; col++) {
			cout << result[row][col] << ' ';
		}
		
		cout << '\n';
	}
			
	return 0;
}