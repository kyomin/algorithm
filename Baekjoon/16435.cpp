#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> fruits;
	int N, L;
	cin >> N >> L;

	fruits.resize(N);

	for (int i = 0; i < N; i++)
		cin >> fruits[i];

	sort(fruits.begin(), fruits.end());

	for (int i = 0; i < N; i++) {
		if (fruits[i] <= L)
			L += 1;
		else
			break;
	}

	cout << L << '\n';

	return 0;
}