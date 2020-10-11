#include <iostream>

using namespace std;

int main() {
	int index;
	int N, M;
	cin >> N;

	M = 2 * (N - 1);

	for (int i = 1; i*(i - 1) <= M; i++)
		index = i;

	if (index % 2 == 1) {
		int son = index;
		int mom = 1;

		int start = 1 + ((index*(index - 1)) / 2);

		for (int i = start; i < N; i++) {
			son -= 1;
			mom += 1;
		}

		cout << son << '/' << mom << endl;
	}
	else {
		int son = 1;
		int mom = index;

		int start = 1 + ((index*(index - 1)) / 2);

		for (int i = start; i < N; i++) {
			son += 1;
			mom -= 1;
		}

		cout << son << '/' << mom << endl;
	}

	return 0;
}