#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = 0;
	int N, M;
	vector<int> plusPos;
	vector<int> minusPos;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num < 0) {
			num *= -1;
			minusPos.push_back(num);
		}
		else {
			plusPos.push_back(num);
		}
	}

	sort(plusPos.begin(), plusPos.end());
	sort(minusPos.begin(), minusPos.end());

	int plusPosLen = plusPos.size();
	int minusPosLen = minusPos.size();

	if (plusPosLen != 0 && minusPosLen != 0) {
		if (plusPos[plusPosLen - 1] > minusPos[minusPosLen - 1]) {
			ans += plusPos[plusPosLen - 1];

			for (int i = plusPosLen - 1 - M; i >= 0; i -= M)
				ans += plusPos[i] * 2;

			for (int i = minusPosLen - 1; i >= 0; i -= M)
				ans += minusPos[i] * 2;
		}
		else {
			ans += minusPos[minusPosLen - 1];

			for (int i = plusPosLen - 1; i >= 0; i -= M)
				ans += plusPos[i] * 2;

			for (int i = minusPosLen - 1 - M; i >= 0; i -= M)
				ans += minusPos[i] * 2;
		}
	}
	else if (plusPosLen != 0 && minusPosLen == 0) {
		ans += plusPos[plusPosLen - 1];

		for (int i = plusPosLen - 1 - M; i >= 0; i -= M)
			ans += plusPos[i] * 2;
	}
	else if (plusPosLen == 0 && minusPosLen != 0) {
		ans += minusPos[minusPosLen - 1];

		for (int i = minusPosLen - 1 - M; i >= 0; i -= M)
			ans += minusPos[i] * 2;
	}

	cout << ans << '\n';

	return 0;
}