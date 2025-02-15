#include <iostream>

using namespace std;

int main() {
	int sum = 0;

	for (int i = 0; i < 6; i++) {
		char result;
		cin >> result;

		if (result == 'W')
			sum++;
	}

	int group;
	if (sum == 5 || sum == 6)
		group = 1;
	else if (sum == 3 || sum == 4)
		group = 2;
	else if (sum == 1 || sum == 2)
		group = 3;
	else
		group = -1;

	cout << group << '\n';

	return 0;
}