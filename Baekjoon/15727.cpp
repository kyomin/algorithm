#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int L, curL=0, t=0;

	cin >> L;

	while (curL < L) {
		curL += 5;
		t++;
	}

	cout << t << '\n';

	return 0;
}