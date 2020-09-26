#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int mushroom[10];
vector<int> results;

void simulation(int idx, int sum) {
	results.push_back(sum);

	// 마지막 인덱스에 도달한 경우에 종료
	if (idx == 9)
		return;

	simulation(idx + 1, sum += mushroom[idx + 1]);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 10; i++)
		cin >> mushroom[i];

	simulation(0, mushroom[0]);

	int len = results.size();
	int diff = abs(results[0] - 100);
	int ans = results[0];

	for (int i = 1; i < len; i++) {
		if (diff > abs(results[i] - 100)) {
			diff = abs(results[i] - 100);
			ans = results[i];
		}
		else if (diff == abs(results[i] - 100)) {
			if (results[i] > ans)
				ans = results[i];
		}
	}

	cout << ans << '\n';

	return 0;
}