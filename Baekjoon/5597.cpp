#include <iostream>

using namespace std;

int main() {
	bool A[31];

	for (int i = 1; i <= 30; i++)
		A[i] = false;

	for (int i = 1; i <= 28; i++) {
		int n;
		cin >> n;

		A[n] = true;
	}

	for (int i = 1; i <= 30; i++)
		if (!A[i])
			cout << i << '\n';
		
	return 0;
}