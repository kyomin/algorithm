#include <iostream>
using namespace std;

int room[1000000];

int main() {
	int N;
	int count = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> room[i];
	}

	for (int i = 0; i < N; i++) {
		if (room[i] == 1) {
			count++;

			// right button 1
			if (room[i + 1] == 1) {
				room[i + 1] = 0;
			}
			else {
				room[i + 1] = 1;
			}
			
			// right button 2
			if (room[i + 2] == 1) {
				room[i + 2] = 0;
			}
			else {
				room[i + 2] = 1;
			}
		}
	}

	cout << count;

	return 0;
}