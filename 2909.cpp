#include <iostream>
#include <string>

using namespace std;

// 10^x
int pow10(int x) {
	if (x == 0)
		return 1;

	return 10 * pow10(x - 1);
}

int main() {
	int price, money, zeroCnt;
	cin >> price >> zeroCnt;

	money = pow10(zeroCnt);

	int remainder = price % money;

	string str = to_string(remainder);

	int num = (int)(str[0] - '0');

	// 내림의 대상이라면
	if (num < 5) {
		price -= remainder;
	}
	else {
		price += (money - remainder);
	}

	cout << price << '\n';

	return 0;
}