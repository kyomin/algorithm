#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];

vector<pair<int, int>> vc;
vector<int> temp;

void dfs(int cnt) {
	if (temp.size() == 2) {
		vc.push_back(make_pair(temp[0], temp[1]));

		return;
	}

	for (int i = cnt; i < 9; i++) {
		if (temp.size() < 2) {
			temp.push_back(arr[i]);
			dfs(i + 1);
			temp.pop_back();
		}
	}
}

int main() {
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9);

	// 아래 함수로 9C2에 해당하는 모든 쌍이 추가된다.
	dfs(0);

	int len = vc.size();

	for (int i = 0; i < len; i++) {
		int temp = vc[i].first + vc[i].second;

		if (sum - temp == 100)
		{
			for (int j = 0; j < 9; j++)
				if (arr[j] != vc[i].first && arr[j] != vc[i].second)
					cout << arr[j] << '\n';

			break;
		}
	}

	return 0;
}