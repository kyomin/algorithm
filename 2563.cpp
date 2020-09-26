#include <iostream>

using namespace std;

bool check[1000][1000];

int main() {
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int W, H;

		cin >> W >> H;

		for (int h = H; h < H + 10; h++) {
			for (int w = W; w < W + 10; w++) {
				if (!check[h][w])
					check[h][w] = true;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (check[i][j])
				ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}