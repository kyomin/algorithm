#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K;
int Arr[100][100];

int solve() {
	int r_size = 3, c_size = 3;

	for (int t = 0; t <= 100; t++) {
		if (Arr[R][C] == K) return t;

		if (r_size >= c_size) {
			// R ���� ����
			for (int r = 0; r < r_size; r++) {
				vector<pair<int, int>> nums;	// first : ��, second : ����
				int cnt[101] = { 0 };			// ������ ���� �� ����. ���Ҵ� 100 ������ �ڿ����̹Ƿ�	
				
				for (int c = 0; c < c_size; c++)
					cnt[Arr[r][c]]++;

				for (int c = 1; c <= 100; c++) {
					if (cnt[c] > 0)
						nums.push_back(make_pair(cnt[c], c));
				}
				
				// ����Ʈ�� first(��) �������� �����ϰ� �ȴ�.
				sort(nums.begin(), nums.end());

				int idx = 0;

				for (auto p : nums) {
					// 100�� �Ѿ�� ����� ���� ó��
					if (idx >= 99) break;

					Arr[r][idx++] = p.second;
					Arr[r][idx++] = p.first;
				}

				// ���� ���� ū ���̷� ������Ʈ
				c_size = max(c_size, idx);

				for (; idx < 100; idx++)
					Arr[r][idx] = 0;
			}
		}
		else {
			// C ���� ����
			for (int c = 0; c < c_size; c++) {
				vector<pair<int, int>> nums;	// first : ��, second : ����
				int cnt[101] = { 0 };			// ������ ���� �� ����. ���Ҵ� 100 ������ �ڿ����̹Ƿ�	

				for (int r = 0; r < r_size; r++)
					cnt[Arr[r][c]]++;

				for (int c = 1; c <= 100; c++) {
					if (cnt[c] > 0)
						nums.push_back(make_pair(cnt[c], c));
				}

				// ����Ʈ�� first(��) �������� �����ϰ� �ȴ�.
				sort(nums.begin(), nums.end());

				int idx = 0;

				for (auto p : nums) {
					// 100�� �Ѿ�� ����� ���� ó��
					if (idx >= 99) break;

					Arr[idx++][c] = p.second;
					Arr[idx++][c] = p.first;
				}

				// ���� ���� ū ���̷� ������Ʈ
				r_size = max(r_size, idx);
		
				// ������ �� 0���� ä���ֱ�
				for (; idx < 100; idx++)
					Arr[idx][c] = 0;
			}
		}
	}

	return -1;
}

int main() {
	cin >> R >> C >> K;
	--R;
	--C;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> Arr[i][j];

	cout << solve() << '\n';

	return 0;
}