#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	
	for (test_case = 1; test_case <= 10; ++test_case) {
		vector<int> buildings;
		int W;
		cin >> W;

		buildings.resize(W);

		for (int w = 0; w < W; w++)
			cin >> buildings[w];

		int ans = 0;

		// 양 끝 2개는 빼고서 고려한다.
		for (int w = 2; w < (W - 2); w++) {
			int building = buildings[w];
			
			int left_max = max(buildings[w - 1], buildings[w - 2]);
			int right_max = max(buildings[w + 1], buildings[w + 2]);

			// 양 옆 빌딩들이 자기보다 작은 경우에만 조성권을 확보할 수 있다.
			if (building <= left_max || building <= right_max)
				continue;

			if (left_max > right_max)
				ans += (building - left_max);
			else
				ans += (building - right_max);
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}

	return 0;
}