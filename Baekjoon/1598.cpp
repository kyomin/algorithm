#include <iostream>
#include <cmath>

using namespace std;

// return (row, col)
pair<int, int> findPos(int n) {
	pair<int, int> ret;
	int row;
	int col;

	if (n % 4 == 0) {
		row = 4;
		col = n / 4;

		ret = { row, col };
	}
	else if ((n + 1) % 4 == 0) {
		row = 3;
		col = (n + 1) / 4;

		ret = { row, col };
	}
	else if ((n + 2) % 4 == 0){
		row = 2;
		col = (n + 2) / 4;

		ret = { row, col };
	}
	else if ((n + 3) % 4 == 0) {
		row = 1;
		col = (n + 3) / 4;

		ret = { row, col };
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	pair<int, int> pos1, pos2;
	int n1, n2;
	cin >> n1 >> n2;

	pos1 = findPos(n1);
	pos2 = findPos(n2);

	int ans = abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);

	cout << ans << '\n';

	return 0;
}