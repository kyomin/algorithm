#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

int main() {
	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> myMap(N, vector<int>(M, 0));
	
	int min = 300;
	int max = -1;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> myMap[r][c];

			if (min > myMap[r][c]) {
				min = myMap[r][c];
			}

			if (max < myMap[r][c]) {
				max = myMap[r][c];
			}
		}
	}

	int result = INF;
	int result_h = -1;

	for (int h = min; h <= max; h++) {
		int time = 0;
		int temp_B = B;

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				int now = myMap[r][c];

				if (now > h) {
					int diff = now - h;

					time += (diff * 2);

					temp_B += diff;
				}
				else if (now < h) {
					int diff = h - now;

					time += diff;

					temp_B -= diff;
				}
			}
		}

		if (result >= time && temp_B >= 0) {
			result = time;
			result_h = h;
		}
	}

	cout << result << ' ' << result_h << endl;

	return 0;
}