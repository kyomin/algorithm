#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int sum = A + B;
	int price = C * 2;

	if (sum >= price)
		cout << sum - price << endl;
	else
		cout << sum << endl;

	return 0;
}