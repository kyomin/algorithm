#include <iostream>

using namespace std;

int main() {
	int L;
	cin >> L;

	for (int l = 0; l < L; l++) {
		int N;
		char C;
		cin >> N >> C;

		for (int n = 0; n < N; n++)
			cout << C;

		cout << endl;
	}

	return 0;
}