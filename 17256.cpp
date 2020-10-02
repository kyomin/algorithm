#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int ax, ay, az;
	int cx, cy, cz;

	cin >> ax >> ay >> az;
	cin >> cx >> cy >> cz;

	cout << cx - az << ' ' << cy / ay << ' ' << cz - ax << '\n';

	return 0;
}