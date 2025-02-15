#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		int sum = 0;

		for (int i = 1; i < N; i++)
			if (N%i == 0)
				sum += i;

		if (sum < N)
			cout << "Deficient" << '\n';
		else if(sum == N)
			cout << "Perfect" << '\n';
		else
			cout << "Abundant" << '\n';
	}

	return 0;
}