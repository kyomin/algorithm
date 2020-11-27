#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		int first, second;
		cin >> first >> second;

		if (first == 0 && second == 0)
			break;

		if (first > second)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}

	return 0;
}