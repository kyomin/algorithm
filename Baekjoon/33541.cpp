#include <iostream>
#include <cmath>
using namespace std;

int main() {
	bool found = false;
	int ans;
	int X;
	cin >> X;


	for (int year = X + 1; year <= 9999; year++) {
		int a = year / 100;
		int b = year % 100;
		int calculatedYear = pow(a + b, 2);

		if (year == calculatedYear) {
			found = true;
			ans = calculatedYear;
			
			break;
		}
	}

	if (found)
		cout << ans << endl;
	else
		cout << -1 << endl;

	return 0;
}