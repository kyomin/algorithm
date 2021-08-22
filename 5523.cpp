#include <iostream>

using namespace std;

int main() {
	int win1 = 0;
	int win2 = 0;
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int a, b;
		cin >> a >> b;

		if (a > b)
			win1++;

		if (a < b)
			win2++;
	}

	cout << win1 << ' ' << win2 << endl;

	return 0;
}