#include <iostream>

using namespace std;

int main() {
	int ascend, descend, length;
	cin >> ascend >> descend >> length;

	if (ascend > length) {
		cout << 1 << '\n';
		return 0;
	}

	int remainder = length % (ascend - descend);
	int quotient = length / (ascend - descend);

	if (remainder != 0) {
		cout << quotient + 1 << '\n';
	}
	else {
		cout << quotient - 1 << '\n';
	}

	return 0;
}