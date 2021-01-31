#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	for (int t = 1; t <= 10; t++) {
		vector<int> heights;
		int dump;
		cin >> dump;

		heights.resize(100);

		for (int i = 0; i < 100; i++)
			cin >> heights[i];

		for (int i = 0; i < dump; i++) {
			// 가장 높은 곳과 가장 낮은 곳을 추출한다.
			int max_height = *max_element(heights.begin(), heights.end());
			int min_height = *min_element(heights.begin(), heights.end());

			// 만일 가장 높은 곳과 가장 낮은 곳의 높이가 같다면 더 이상 평탄화를 수행할 필요가 없다.
			if (max_height == min_height)
				break;

			// 가장 높은 곳과 가장 낮은 곳의 인덱스를 찾는다.
			int max_idx;
			int min_idx;
			for (int j = 0; j < 100; j++) {
				if (heights[j] == max_height) {
					max_idx = j;
					break;
				}
			}

			for (int j = 0; j < 100; j++) {
				if (heights[j] == min_height) {
					min_idx = j;
					break;
				}
			}

			// 평탄화 수행!
			heights[max_idx]--;
			heights[min_idx]++;
		}

		// 평탄화 완료 후 최고점과 최저점의 차를 구한다.
		int max_height = *max_element(heights.begin(), heights.end());
		int min_height = *min_element(heights.begin(), heights.end());

		cout << '#' << t << ' ' << (max_height - min_height) << '\n';
	}

	return 0;
}