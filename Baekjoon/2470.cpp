#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2000000000;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> ans(2);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int left = 0;
	int right = N - 1;
	int min = INF;
	while (left < right) {
		int sum = arr[left] + arr[right];
		 
		// ���̰� �۾��� ������ ����
		if (min > abs(sum)) {
			min = abs(sum);
			ans[0] = arr[left];
			ans[1] = arr[right];

			// ���� �̻����� ��
			if (sum == 0)
				break;
		}

		if (sum < 0)
			left++;
		else
			right--;
	}

	cout << ans[0] << ' ' << ans[1] << endl;

	return 0;
}