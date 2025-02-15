#include <iostream>

using namespace std;

int main() {
	int A, B, C, D, P;
	cin >> A >> B >> C >> D >> P;

	int X = A * P;
	int Y = B;

	if (P > C)
		Y += (P - C)*D;

	if (X < Y)
		cout << X << endl;
	else
		cout << Y << endl;

	return 0;
}