#include <iostream>

using namespace std;

int main() {
	int S, M, L;
	cin >> S >> M >> L;

	int result = S + 2 * M + 3 * L;

	if (result < 10)
		cout << "sad" << endl;
	else
		cout << "happy" << endl;

	return 0;
}