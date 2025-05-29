#include <iostream>
using namespace std;

int main() {
	int maxCost = 0;
	int sum = 0;
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int cost;
		cin >> cost;

		if (cost > maxCost) {
			maxCost = cost;
		}

		sum += cost;
	}

	cout << sum - maxCost << endl;

	return 0;
}