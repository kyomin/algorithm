#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	if (N > M)
		cout << (M / 2) << endl;
	else
		cout << (N / 2) << endl;

	return 0;
}