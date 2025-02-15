#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int n1 = 1;
	int n2 = 1;

	for (int i = 0; i < K; i++)
		n1 *= (N - i);

	for (int i = K; i >= 1; i--)
		n2 *= i;

	cout << n1 / n2 << endl;

	return 0;
}