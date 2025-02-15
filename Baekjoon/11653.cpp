#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1)
		return 0;

	for (int i = 2; i*i <= N; i++) {
		while (true) {
			if (N%i == 0) {
				cout << i << '\n';
				N /= i;
			}
			else
				break;
		}
	}

	if (N > 1)
		cout << N << endl;

	return 0;
}