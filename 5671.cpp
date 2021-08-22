#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {
	while (true) {
		bool check[10];
		int cnt = 0;
		int N, M;
		if (scanf("%d %d", &N, &M) == -1)
			break;

		for (int num = N; num <= M; num++) {
			memset(check, false, sizeof(check));

			string num_str = to_string(num);
			int len = num_str.length();
			bool judge = true;

			for (int i = 0; i < len; i++) {
				int n = (int)(num_str[i] - '0');

				if (!check[n])
					check[n] = true;
				else {
					judge = false;
					break;
				}
			}

			if (judge)
				cnt++;
		}

		cout << cnt << endl;
	}

	return 0;
}