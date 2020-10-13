#include <iostream>

using namespace std;

int main() {
	int e, f, c;
	cin >> e >> f >> c;

	// 먹을 수 있는 총 개수
	int sum = (e + f) / c;

	// 가질 수 있는 빈 병의 개수
	int having = ((e + f) / c) + ((e + f) % c);

	while (having >= c) {
		int temp = having;
		sum += temp / c;
		having = (temp / c) + (temp%c);
	}

	cout << sum << '\n';

	return 0;
}