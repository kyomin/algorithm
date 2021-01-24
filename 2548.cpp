#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 987654321;

bool check[10001];
vector<int> nums;
int N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int diff = INF;		// ������ ���� �ϴ� �ִ����� �ʱ�ȭ


	cin >> N;
	nums.resize(N);

	for (int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	int ans;

	for (int i = 0; i < N; i++) {
		int num = nums[i];

		// �̹� ����ߴ� ���ڶ�� �ǳ� �ڴ�.
		if (check[num])
			continue;

		int sum = 0;

		for (int j = 0; j < N; j++) 
			sum += abs(nums[j] - num);

		if (sum < diff) {
			diff = sum;
			ans = num;
		}
	}

	cout << ans << '\n';

	return 0;
}