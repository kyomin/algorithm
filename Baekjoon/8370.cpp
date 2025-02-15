#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n1, k1, n2, k2;
	cin >> n1 >> k1 >> n2 >> k2;

	cout << (n1*k1) + (n2*k2) << endl;

	return 0;
}