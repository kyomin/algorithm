#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[40][40];

int main() {
	int T;
	int R, C;
	cin >> R >> C;

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> map[r][c];

	cin >> T;

	vector<int> filtered_img;
	for (int r = 0; (r + 3) <= R; r++) {
		for (int c = 0; (c + 3) <= C; c++) {
			vector<int> v;

			for (int i = r; i < (r + 3); i++)
				for (int j = c; j < (c + 3); j++)
					v.push_back(map[i][j]);
			
			sort(v.begin(), v.end());
			int mid = v[4];
			filtered_img.push_back(mid);
		}
	}

	int cnt = 0;
	int len = filtered_img.size();
	for (int i = 0; i < len; i++)
		if (filtered_img[i] >= T)
			cnt++;

	cout << cnt << endl;

	return 0;
}