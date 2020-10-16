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
			// R 연산 수행
			for (int r = 0; r < r_size; r++) {
				vector<pair<int, int>> nums;	// first : 빈도, second : 숫자
				int cnt[101] = { 0 };			// 숫자의 등장 빈도 세기. 원소는 100 이하의 자연수이므로	
				
				for (int c = 0; c < c_size; c++)
					cnt[Arr[r][c]]++;

				for (int c = 1; c <= 100; c++) {
					if (cnt[c] > 0)
						nums.push_back(make_pair(cnt[c], c));
				}
				
				// 디폴트는 first(빈도) 기준으로 정렬하게 된다.
				sort(nums.begin(), nums.end());

				int idx = 0;

				for (auto p : nums) {
					// 100을 넘어가는 경우의 예외 처리
					if (idx >= 99) break;

					Arr[r][idx++] = p.second;
					Arr[r][idx++] = p.first;
				}

				// 행의 가장 큰 길이로 업데이트
				c_size = max(c_size, idx);

				for (; idx < 100; idx++)
					Arr[r][idx] = 0;
			}
		}
		else {
			// C 연산 수행
			for (int c = 0; c < c_size; c++) {
				vector<pair<int, int>> nums;	// first : 빈도, second : 숫자
				int cnt[101] = { 0 };			// 숫자의 등장 빈도 세기. 원소는 100 이하의 자연수이므로	

				for (int r = 0; r < r_size; r++)
					cnt[Arr[r][c]]++;

				for (int c = 1; c <= 100; c++) {
					if (cnt[c] > 0)
						nums.push_back(make_pair(cnt[c], c));
				}

				// 디폴트는 first(빈도) 기준으로 정렬하게 된다.
				sort(nums.begin(), nums.end());

				int idx = 0;

				for (auto p : nums) {
					// 100을 넘어가는 경우의 예외 처리
					if (idx >= 99) break;

					Arr[idx++][c] = p.second;
					Arr[idx++][c] = p.first;
				}

				// 행의 가장 큰 길이로 업데이트
				r_size = max(r_size, idx);
		
				// 나머지 값 0으로 채워주기
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