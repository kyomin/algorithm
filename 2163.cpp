#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	cout << N * M - 1 << '\n';

	return 0;
}