#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int C, D;
	cin >> C >> D;

	cout << min(A + D, B + C) << endl;

	return 0;
}