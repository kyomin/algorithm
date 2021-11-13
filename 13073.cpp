#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int s1 = 0;
		int s2 = 0;
		int s3 = 0;
		int N;
		cin >> N;

		for (int num = 1; num <= N; num++)
			s1 += num;

		// È¦¼ö ºÎºÐ
		int odd = 1;
		int oddCnt = 1;
		while (oddCnt <= N) {
			s2 += odd;

			odd += 2;
			oddCnt++;
		}

		// Â¦¼ö ºÎºÐ
		int even = 2;
		int evenCnt = 1;
		while (evenCnt <= N) {
			s3 += even;

			even += 2;
			evenCnt++;
		}

		cout << s1 << ' ' << s2 << ' ' << s3 << endl;
	}

	return 0;
}