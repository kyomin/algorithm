#include <iostream>
#include <vector>

using namespace std;

int main() {
	bool curMilk[3] = { false, };
	vector<int> milkStores;
	int cnt = 0;
	int N;
	cin >> N;

	milkStores.resize(N);
	curMilk[0] = true;

	for (int n = 0; n < N; n++)
		cin >> milkStores[n];

	for (int i = 0; i < N; i++) {
		int milk = milkStores[i];

		if (curMilk[milk]) {
			curMilk[milk] = false;
			
			cnt++;
			
			milk++;
			milk %= 3;

			curMilk[milk] = true;
		}
	}

	cout << cnt << '\n';

	return 0;
}