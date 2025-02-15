#include <iostream>
using namespace std;

int main() {
	char ans;
	int A, B, C;
	cin >> A >> B >> C;

	if (A != B && A != C)
		ans = 'A';
	else if (B != A && B != C)
		ans = 'B';
	else if (C != A && C != B)
		ans = 'C';
	else
		ans = '*';

	cout << ans << endl;

	return 0;
}