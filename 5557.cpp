#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll d[100][21];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	n -= 1;		// 마지막 수는 따로 입력받기 위해 1을 빼줌.

	vector<int> nums(n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	int last;
	cin >> last;	// 마지막 수 입력받음

	// 첫 번째 수에 대한 처리
	d[0][nums[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - nums[i] >= 0)
				d[i][j] += d[i - 1][j - nums[i]];

			if (j + nums[i] <= 20)
				d[i][j] += d[i - 1][j + nums[i]];
		}
	}

	// n-1번째까지 수로 last를 만들 수 있는 경우의 개수가 정답
	cout << d[n - 1][last] << endl;

	return 0;
}