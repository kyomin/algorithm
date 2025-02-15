#include <iostream>
#include <string>

using namespace std;

string map[100];

int main() {
	int N;
	cin >> N;

	for (int row = 0; row < N; row++)
		cin >> map[row];

	int width = 0;
	int height = 0;

	// for width
	for (int row = 0; row < N; row++) {
		int cnt = 0;

		for (int col = 0; col < N; col++) {
			if (map[row][col] == 'X') {
				if (cnt >= 2)
					width++;
				
				cnt = 0;
			}
			else {
				cnt++;
			}
		}

		if (cnt >= 2)
			width++;
	}

	// for height
	for (int col = 0; col < N; col++) {
		int cnt = 0;

		for (int row = 0; row < N; row++) {
			if (map[row][col] == 'X') {
				if (cnt >= 2)
					height++;

				cnt = 0;
			}
			else {
				cnt++;
			}
		}

		if (cnt >= 2)
			height++;
	}

	cout << width << ' ' << height << endl;

	return 0;
}