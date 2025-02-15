#include <iostream>

using namespace std;

int multiTab[500000];
int N;

int maxComputer() {
	int result = multiTab[0];

	for (int i = 1; i < N; i++) {
		result -= 1;
		result += multiTab[i];
	}

	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> multiTab[i];

	cout << maxComputer() << '\n';

	return 0;
}