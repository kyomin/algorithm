#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int left = B - A - 1;
	int right = C - B - 1;

	if (left > right)
		cout << left << endl;
	else
		cout << right << endl;

	return 0;
}