#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int cnt = 0;
		int a, b, c;
		cin >> a >> b >> c;

		for (int x = 1; x <= a; x++)
			for (int y = 1; y <= b; y++)
				for (int z = 1; z <= c; z++)
					if ((x%y == y%z) && (y%z == z%x))
						cnt++;
		
		cout << cnt << endl;
	}

	return 0;
}