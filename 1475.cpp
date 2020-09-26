#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[10];

int main() {
	string N;
	cin >> N;

	int len = N.size();

	// 등장한 숫자 개수를 기록한다.
	for (int i = 0; i < len; i++) {
		int num = (int)(N[i] - '0');
		arr[num] += 1;
	}

	int ans = 0;

	// 6과 9 이외의 숫자를 대상으로 최대를 먼저 구한다.
	for (int i = 0; i < 10; i++) 
		if (i != 6 && i != 9)
			ans = max(ans, arr[i]);

	// 6과 9를 대상으로 필요한 셋트를 구한다.
	ans = max(ans, (arr[6] + arr[9] + 1) / 2);

	cout << ans << endl;

	return 0;
}