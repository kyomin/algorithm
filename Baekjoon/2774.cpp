#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool nums[10];

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		memset(nums, false, sizeof(nums));
		int n;
		cin >> n;

		string str_n = to_string(n);
		int len = str_n.length();

		for (int i = 0; i < len; i++) {
			int idx = (int)(str_n[i] - '0');
			nums[idx] = true;
		}

		int cnt = 0;

		for (int i = 0; i < 10; i++)
			if (nums[i])
				cnt++;

		cout << cnt << endl;
	}

	return 0;
}