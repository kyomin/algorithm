#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int ranking[500000];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> ranking[i];

	sort(ranking, ranking + N);

	unsigned long long result = 0;

	for (int i = 0; i < N; i++)
		result += abs((i + 1) - ranking[i]);

	cout << result << '\n';

	return 0;
}