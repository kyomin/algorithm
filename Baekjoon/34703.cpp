#include <iostream>
using namespace std;

int classes[6];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int day;
		cin >> day;

		classes[day]++;
	}

	int empty_count = 0;

	for (int i = 1; i <= 5; i++) {
		if (classes[i] == 0) {
			empty_count++;
		}
	}

	if (empty_count > 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}