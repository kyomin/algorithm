#include <iostream>

using namespace std;

int main() {
	int L, curL=0, t=0;

	cin >> L;

	while (curL < L) {
		curL += 5;
		t++;
	}

	cout << t << '\n';

	return 0;
}