#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;

	if (B == C)
		cout << -1 << endl;
	else if(B>C)
		cout << -1 << endl;
	else 
		cout << (A / (C - B)) + 1 << endl;

	return 0;
}