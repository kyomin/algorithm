#include <iostream>
using namespace std;

int origin[6] = { 1, 1, 2, 2, 2, 8 };

int main() {
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;

		origin[i] -= n;
	}

	for (int i = 0; i < 5; i++)
		cout << origin[i] << ' ';
	
	cout << origin[5] << endl;

	return 0;
}