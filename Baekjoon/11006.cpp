#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		int total = (M * 2);
		int U = total - N;
		
		cout << U << ' ' << (M - U) << endl;
	}

	return 0;
}