#include <iostream>

using namespace std;

unsigned long check[300000 + 1];

// 정수용 거듭곱 함수
unsigned long pow(int x, int y) {
	unsigned long ans = 1;

	for (int i = 0; i < y; i++)
		ans *= x;

	return ans;
}

unsigned long next(int a, int p) {
	unsigned long ans = 0;

	while (a != 0) {
		ans += pow(a % 10, p);
		a /= 10;
	}

	return ans;
}

int length(int A, int P, int cnt) {
	// 이미 방문한 수(정점)라면
	if (check[A] != 0)
		return check[A] - 1;

	// 아직 방문한 정점(수)이 아니라면
	check[A] = cnt;	// 해당 정점에 해당 수까지 오는 길이 저장
	int B = next(A, P);

	return length(B, P, cnt + 1);
}

int main() {
	for (int i = 1; i <= 9999; i++)
		check[i] = 0;

	int A, P;
	cin >> A >> P;

	int cnt = 1;

	cout << length(A, P, cnt) << endl;

	return 0;
}