#include <iostream>
using namespace std;

int num[1000];
int N, t;

void decrease(int a, int c, int s) {
	if (a == c) {
		t++;

		if (t == N) {
			for (int i = 0; i < a; i++)
				cout << num[i];

			cout << endl;
		}
	}
	else if (a > c) {
		return;
	}
	else {
		for (int i = 0; i <= s; i++) {
			if (i == 0 && a + 1 != c)
				continue;

			num[a] = i;

			decrease(a + 1, c, i - 1);
		}
	}
}

int main() {
	cin >> N;

	if (N <= 10)
		cout << N - 1 << endl;
	else if (N > 1023)
		cout << -1 << endl;
	else {
		t = 10;
		for (int i = 2; i < 1000; i++)
			decrease(0, i, 9);
	}

	return 0;
}