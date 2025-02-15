#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int ans;

	// a + b = c^2
	int a, b, c;
	cin >> a >> b >> c;

	if (a == 0)
		ans = (int)pow(c, 2) - b;
	else if (b == 0)
		ans = (int)pow(c, 2) - a;
	else
		ans = (int)sqrt(a + b);

	cout << ans << endl;

	return 0;
}