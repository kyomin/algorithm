#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	int count = 1;
	int sum = 1;

	while (true) {
		if (6 * sum + 1 >= N)
			break;

		count += 1;
		sum += count;
	}

	cout << count + 1 << endl;

	return 0;
}