#include <iostream>
using namespace std;

int main() {
	int Y = 0;
	int M = 0;
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int q;
		int price;
		cin >> price;

		// 영식 요금제 먼저 계산
		q = price / 30;
		Y += ((q + 1) * 10);

		// 민식 요금제 계산
		q = price / 60;
		M += ((q + 1) * 15);
	}

	if (Y < M)
		cout << 'Y' << ' ' << Y << endl;
	else if (Y > M)
		cout << 'M' << ' ' << M << endl;
	else
		cout << 'Y' << ' ' << 'M' << ' ' << Y << endl;

	return 0;
}