#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	B += C;

	int minutes = B % 60;
	int hours_carry = B / 60;
	int hours = A + hours_carry;

	hours = hours % 24;

	cout << hours << ' ' << minutes;

	return 0;
}