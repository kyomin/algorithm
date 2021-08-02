#include <iostream>

using namespace std;

int main() {
	int t = 1;

	while (true) {
		int n0;
		cin >> n0;

		if (n0 == 0)
			break;

		int n1 = 3 * n0;
		int n2;

		if (n1 % 2 == 0)
			n2 = (n1 / 2);
		else
			n2 = (n1 + 1) / 2;

		int n3 = 3 * n2;
		int n4 = n3 / 9;

		if (n1 % 2 == 0)
			cout << t << ". even " << n4 << endl;
		else
			cout << t << ". odd " << n4 << endl;

		t++;
	}

	return 0;
}