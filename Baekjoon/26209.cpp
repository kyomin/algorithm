#include <iostream>
using namespace std;

int main() {
	bool flag = true;

	for (int i = 0; i < 8; i++) {
		int num;
		cin >> num;

		if (num == 9) {
			flag = false;
		}
	}

	if (flag) {
		cout << 'S' << endl;
	}
	else {
		cout << 'F' << endl;
	}

	return 0;
}