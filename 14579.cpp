#include <iostream>
using namespace std;

typedef unsigned long long ll;

int main() {
	ll mul = 1;
	ll a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		mul *= ((i*(i + 1)) / 2);
		mul %= 14579;
	}
	
	cout << mul << endl;

	return 0;
}