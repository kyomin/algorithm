#include <iostream>
using namespace std;

int main() {
	int X;
	int N;
	cin >> X;
	cin >> N;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		sum += (a*b);
	}

	if (sum == X)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}