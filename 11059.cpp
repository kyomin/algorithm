#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int ans = 0;
	string str;
	int len;
	int max_even;

	cin >> str;
	len = str.size();

	if (len % 2 == 0)
		max_even = len;
	else
		max_even = len - 1;

	for (int i = 0; i < len; i++) {
		int max_even_tmp = max_even;


		while (max_even_tmp >= 2) {
			int num = max_even_tmp / 2;

			if (i + num >= len) {
				max_even_tmp -= 2;
				continue;
			}

			if (i + num + num > len) {
				max_even_tmp -= 2;
				continue;
			}

			string left = str.substr(i, num);
			string right = str.substr(i + num, num);

			int left_num = 0;
			int right_num = 0;

			// 왼쪽 값 계산
			for (int i = 0; i < num; i++)
				left_num += (int)(left[i] - '0');

			// 오른쪽 값 계산
			for (int i = 0; i < num; i++)
				right_num += (int)(right[i] - '0');

			if (left_num == right_num)
				ans = max(ans, max_even_tmp);

			max_even_tmp -= 2;
		}
	}

	cout << ans << '\n';

	return 0;
}