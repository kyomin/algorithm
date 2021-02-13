#include <iostream>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	if (A > B && A == 3 && B == 1)
		cout << 'B' << '\n';
	else if (A < B && A == 1 && B == 3)
		cout << 'A' << '\n';
	else if (A > B)
		cout << 'A' << '\n';
	else if (A < B)
		cout << 'B' << '\n';

	return 0;
}