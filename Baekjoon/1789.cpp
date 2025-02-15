#include <iostream>

using namespace std;

int main() {
	unsigned long N = 1;
	unsigned long sum = 1;
	unsigned long S;
	cin >> S;

	while (true) {
		if (sum == S)
			break;
		else if (sum < S) {
			N += 1;
			sum += N;
		}
		else if (sum > S)
		{
			N -= 1;
			break;
		}
	}

	cout << N << endl;

	return 0;
}