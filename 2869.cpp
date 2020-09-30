#include <iostream>

using namespace std;

int main() {
	int day;
	int A, B, V;
	cin >> A >> B >> V;

	day = (V - B - 1) / (A - B) + 1;

	cout << day << '\n';

	return 0;
}