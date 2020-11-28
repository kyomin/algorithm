#include <iostream>
#include <string>

using namespace std;

int cups[3] = { 1, 0, 0 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string orders;
	cin >> orders;

	int len = orders.size();

	for (int i = 0; i < len; i++) {
		char order = orders[i];

		if (order == 'A') {
			int temp = cups[0];
			cups[0] = cups[1];
			cups[1] = temp;

			continue;
		}

		if (order == 'B') {
			int temp = cups[1];
			cups[1] = cups[2];
			cups[2] = temp;

			continue;
		}

		if (order == 'C') {
			int temp = cups[0];
			cups[0] = cups[2];
			cups[2] = temp;

			continue;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (cups[i] == 1) {
			cout << i + 1 << '\n';

			break;
		}
	}

	return 0;
}