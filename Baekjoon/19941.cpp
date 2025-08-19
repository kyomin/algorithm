#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<bool> check(N, false);	// ÇÜ¹ö°Å ¸Ô¾ú´ÂÁö Ã¼Å©
	string str;
	cin >> str;

	for (int i = 0; i < N; i++) {		
		// »ç¶÷ÀÌ¸é
		if (str[i] == 'P') {
			int start = (i - K) >= 0 ? (i - K) : 0;
			bool flag = false;

			for (int j = start; j < i; j++) {
				// ÇÜ¹ö°ÅÀÌ°í, ¾È ¸Ô¾úÀ¸¸é
				if (str[j] == 'H' && !check[j]) {
					check[j] = true;
					flag = true;

					break;
				}
			}

			if (flag) {
				continue;
			}

			// ¿ÞÂÊ¿¡¼­ ÇÜ¹ö°Å¸¦ ¸ø ¸Ô¾úÀ¸¸é ¿À¸¥ÂÊ Å½»ö
			int end = (i + K) < N ? (i + K) : N - 1;

			for (int j = i + 1; j <= end; j++) {
				// ÇÜ¹ö°ÅÀÌ°í, ¾È ¸Ô¾úÀ¸¸é
				if (str[j] == 'H' && !check[j]) {
					check[j] = true;

					break;
				}
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (check[i]) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}