#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int W, H, N;
	vector<pair<int, int>> stores;
	int my_position, my_dist;

	cin >> W >> H;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int position, dist;
		cin >> position >> dist;

		stores.push_back({ position, dist });
	}

	cin >> my_position >> my_dist;

	int sum = 0;

	for (int n = 0; n < N; n++) {
		int store_position = stores[n].first;
		int store_dist = stores[n].second;

		// 나와 같은 위치 선상이면
		if (my_position == store_position) {
			sum += abs(my_dist - store_dist);
			continue;
		}

		// 북 - 남 또는 남 - 북이라면
		if ((my_position == 1 || my_position == 2) && (store_position == 1 || store_position == 2)) {
			sum += min((H + store_dist + my_dist), (H + 2 * W - store_dist - my_dist));
			continue;
		}

		// 동 - 서 또는 서 - 동이라면
		if ((my_position == 3 || my_position == 4) && (store_position == 3 || store_position == 4)) {
			sum += min((W + store_dist + my_dist), (W + 2 * H - store_dist - my_dist));
			continue;
		}

		// 북 - 서라면 
		if (my_position == 1 && store_position == 3) {
			sum += (my_dist + store_dist);
			continue;
		}

		// 북 - 동이라면
		if (my_position == 1 && store_position == 4) {
			sum += (W - my_dist + store_dist);
			continue;
		}

		// 남 - 서라면
		if (my_position == 2 && store_position == 3) {
			sum += (my_dist + (H - store_dist));
			continue;
		}

		// 남 - 동이라면
		if (my_position == 2 && store_position == 3) {
			sum += (W - my_dist + (H - store_dist));
			continue;
		}
	}

	cout << sum << '\n';

	return 0;
}