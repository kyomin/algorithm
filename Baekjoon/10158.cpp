#include <iostream>
using namespace std;

int main() {
	int w, h;
	cin >> w >> h;

	int x, y;
	cin >> x >> y;

	int t;
	cin >> t;

	int cycleX = 2 * w;
	int cycleY = 2 * h;

	int movedX = (t + x) % cycleX;
	int movedY = (t + y) % cycleY;

	if (movedX > w) {
		int diff = (movedX - w);
		
		movedX = w - diff;
	}

	if (movedY > h) {
		int diff = (movedY - h);

		movedY = h - diff;
	}

	cout << movedX << ' ' << movedY << endl;

	return 0;
}