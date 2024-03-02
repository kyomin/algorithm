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
		// ���� �� index - ���� �� index
		int diff = arr[i].second - i;

		// �� swap ����Ŭ �� ���� �̵��� �ִ� �� �� �̵��ϹǷ� ����
		if (max_num < diff) {
			max_num = diff;
		}
	}

	// swap�� ���� �ʴ� �������� 1 ������
	cout << max_num + 1 << endl;

	return 0;
}