#include <iostream>

using namespace std;

// 정수의 자릿수를 출력하는 함수
int Digit(int N) {
	int count = 0;

	if (N == 0)
		return 1;

	while (N != 0) {
		N /= 10;
		count++;
	}

	return count;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int count = 0;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		count += Digit(i);

	cout << count << endl;

	return 0;
}