#include <iostream>

using namespace std;

int main() {
	int N, a, b;
	cin >> N >> a >> b;

	// ����� 1���� ����!
	int round = 1;

	while (N != 1) {
		// ���� ����� �ϴ� ����� Ż��!
		if ((a + 1) / 2 == (b + 1) / 2)
			break;
		// �������� ���� Ȧ���� ���.
		else if (N % 2 == 1) {
			a = (a + 1) / 2;
			b = (b + 1) / 2;
			N = (N / 2) + 1;
			round++;
		}
		else {
			a = (a + 1) / 2;
			b = (b + 1) / 2;
			N = (N / 2);
			round++;
		}
	}

	if (N == 1)
		cout << -1 << endl;
	else
		cout << round << endl;

	return 0;
}