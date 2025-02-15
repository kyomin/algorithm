#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int num = 1;

	for (int i = 0; i < N; i++) {
		cout << num << ' ';
		num *= 2;
	}

	cout << num << '\n';

	return 0;
}