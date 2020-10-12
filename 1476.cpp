#include <iostream>

using namespace std;

int main() {
	int x = 1, y = 1, z = 1;
	int count = 1;
	int E, S, M;
	cin >> E >> S >> M;

	while (true) {
		if ((x == E) && (y == S) && (z == M))
			break;

		if (x == 15)
			x = 1;
		else
			x += 1;

		if (y == 28)
			y = 1;
		else
			y += 1;

		if (z == 19)
			z = 1;
		else
			z += 1;

		count++;
	}

	cout << count << endl;

	return 0;
}