#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;

	int *DP = new int[B + 1];

	DP[1] = 1;

	int judge = 2;
	int count = 0;

	for (int i = 2; i <= B; i++) {
		if (count == judge) {
			count = 0;
			judge += 1;
		}

		DP[i] = judge;
		count += 1;
	}

	int sum = 0;

	for (int i = A; i <= B; i++)
		sum += DP[i];

	cout << sum << endl;

	return 0;
}