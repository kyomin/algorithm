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
			// ���� ���� ���� ���� ���� ���� �����Ѵ�.
			int max_height = *max_element(heights.begin(), heights.end());
			int min_height = *min_element(heights.begin(), heights.end());

			// ���� ���� ���� ���� ���� ���� ���� ���̰� ���ٸ� �� �̻� ��źȭ�� ������ �ʿ䰡 ����.
			if (max_height == min_height)
				break;

			// ���� ���� ���� ���� ���� ���� �ε����� ã�´�.
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

			// ��źȭ ����!
			heights[max_idx]--;
			heights[min_idx]++;
		}

		// ��źȭ �Ϸ� �� �ְ����� �������� ���� ���Ѵ�.
		int max_height = *max_element(heights.begin(), heights.end());
		int min_height = *min_element(heights.begin(), heights.end());

		cout << '#' << t << ' ' << (max_height - min_height) << '\n';
	}

	return 0;
}