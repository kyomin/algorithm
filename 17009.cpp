#include <iostream>

using namespace std;

int main() {
	int A = 0;
	int B = 0;

	for(int i=0; i<3; i++) {
		int score;
		cin >> score;

		A += (score*(3 - i));
	}

	for (int i = 0; i < 3; i++) {
		int score;
		cin >> score;

		B += (score*(3 - i));
	}

	if (A > B)
		cout << 'A' << endl;
	else if (A < B)
		cout << 'B' << endl;
	else
		cout << 'T' << endl;

	return 0;
}