#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, S;
	cin >> N >> S;
	vector<int> cows(N);
	for (int i = 0; i < N; i++)
		cin >> cows[i];

	sort(cows.begin(), cows.end());

	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		int cow1 = cows[i];

		for (int j = i + 1; j < N; j++) {
			int cow2 = cows[j];

			if (cow1 + cow2 <= S)
				cnt++;
			else
				break;
		}
	}

	cout << cnt << endl;

	return 0;
}