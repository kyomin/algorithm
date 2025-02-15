#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int result1 = (A + B) % C;
	int result2 = (A*B) % C;

	cout << result1 << endl << result1 << endl << result2 << endl << result2 << endl;

	return 0;
}