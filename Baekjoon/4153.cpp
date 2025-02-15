#include <iostream>
#include <algorithm>

using namespace std;

int pow(int x) {
	return x * x;
}

int main() {
	while (true) {
		int A[3];

		for (int i = 0; i < 3; i++)
			cin >> A[i];

		if (A[0] == 0 && A[1] == 0 && A[2] == 0)
			break;

		sort(A, A + 3);

		if (pow(A[0]) + pow(A[1]) == pow(A[2]))
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}

	return 0;
}