#include <iostream>

using namespace std;

int main() {
	int e, f, c;
	cin >> e >> f >> c;

	// ���� �� �ִ� �� ����
	int sum = (e + f) / c;

	// ���� �� �ִ� �� ���� ����
	int having = ((e + f) / c) + ((e + f) % c);

	while (having >= c) {
		int temp = having;
		sum += temp / c;
		having = (temp / c) + (temp%c);
	}

	cout << sum << '\n';

	return 0;
}