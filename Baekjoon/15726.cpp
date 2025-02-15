#include <iostream>
using namespace std;

int main() {
	double A, B, C;
	cin >> A >> B >> C;

	double ans1 = (A * B) / C;
	double ans2 = (A / B) * C;

	if (ans1 > ans2)
		cout << (int)ans1 << endl;
	else
		cout << (int)ans2 << endl;

	return 0;
}