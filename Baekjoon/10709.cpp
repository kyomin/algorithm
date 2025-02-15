#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char cloud_status[100][100];
	int result[100][100];
	int H, W;
	cin >> H >> W;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> cloud_status[i][j];

	for (int i = 0; i < H; i++) {
		bool judge = false;

		for (int j = 0; j < W; j++) {
			if (!judge && cloud_status[i][j] == '.')
				result[i][j] = -1;
			else if (!judge && cloud_status[i][j] == 'c') {
				result[i][j] = 0;
				judge = true;
			}
			else if (judge && cloud_status[i][j] == 'c')
				result[i][j] = 0;
			else if (judge && cloud_status[i][j] == '.')
				result[i][j] = result[i][j - 1] + 1;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cout << result[i][j] << ' ';

		cout << '\n';
	}

	return 0;
}