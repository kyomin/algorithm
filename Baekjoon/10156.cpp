#include <iostream>

using namespace std;

int main() {
	int K, N, M;
	cin >> K >> N >> M;

	int total = K * N;
	int diff = total - M;

	cout << (diff <= 0 ? 0 : diff) << endl;

	return 0;
}