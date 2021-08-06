#include <iostream>

using namespace std;

int arr[101][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 4; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int a = y1; a < y2; a++)
			for (int b = x1; b < x2; b++)
				arr[a][b] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (arr[i][j] == 1)
				cnt++;

	cout << cnt << '\n';

	return 0;
}