#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// For Fast IO
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> nums(N, 0);

	for (int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	int result = 0;

	for (int k = 0; k < N; k++) {
		// Target Number
		int find = nums[k];

		// Two Pointer
		int s = 0;
		int e = N - 1;

		while (s < e) {
			if (nums[s] + nums[e] == find) {
				// 현재 자기 자신 인덱스는 제외한다
				if (s != k && e != k) {
					result++;
					break;
				}
				else if (s == k) {
					s++;
				}
				else if (e == k) {
					e--;
				}
			}
			else if (nums[s] + nums[e] < find) {
				s++;
			}
			else {
				e--;
			}
		}
	}

	cout << result << endl;

	return 0;
}