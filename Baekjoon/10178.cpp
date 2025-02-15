#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int c, v;
		cin >> c >> v;

		int q = c / v;
		int r = c % v;

		cout << "You get " + to_string(q) + " piece(s) and your dad gets " + to_string(r) + " piece(s).\n";
	}

	return 0;
}