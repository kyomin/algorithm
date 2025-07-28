#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> heights(1001);
	int maxHeight = 0;
	int maxIndex = 0;

	for (int i = 0; i < N; i++) {
		int index, height;
		cin >> index >> height;

		heights[index] = height;

		if (height > maxHeight) {
			maxHeight = height;
			maxIndex = index;			
		}
	}

	int sum = 0;
	int nowHeight = 0;

	for (int i = 0; i <= maxIndex; i++) {
		if (nowHeight < heights[i]) {
			nowHeight = heights[i];
		}

		sum += nowHeight;
	}

	nowHeight = 0;

	for (int i = 1000; i > maxIndex; i--) {
		if (nowHeight < heights[i]) {
			nowHeight = heights[i];
		}

		sum += nowHeight;
	}

	cout << sum << endl;

	return 0;
}