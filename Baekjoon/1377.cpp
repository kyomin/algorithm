#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// fast IO
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first;

		// save index
		arr[i].second = i;
	}

	// O( N * longN )
	sort(arr.begin(), arr.end());

	// O( N )
	int max_num = 0;
	for (int i = 0; i < N; i++) {
		// 정렬 전 index - 정렬 후 index
		int diff = arr[i].second - i;

		// 한 swap 사이클 당 왼쪽 이동은 최대 한 번 이동하므로 갱신
		if (max_num < diff) {
			max_num = diff;
		}
	}

	// swap을 돌지 않는 마지막을 1 더해줌
	cout << max_num + 1 << endl;

	return 0;
}