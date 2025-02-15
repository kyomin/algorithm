#include <iostream>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	int row = K / M;
	int col = K - (row*M);

	cout << row << ' ' << col << endl;

	return 0;
}