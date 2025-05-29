#include <iostream>
using namespace std;

int main() {
	int K;
	int map[6][2];

	cin >> K;

	for (int i = 0; i < 6; i++) 
		cin >> map[i][0] >> map[i][1];
		
	int maxWidth = 0;
	int maxHeight = 0;	
	int maxWidthIndex = -1;
	int maxHeightIndex = -1;

	for (int i = 0; i < 6; i++) {
		int currentLength = map[i][1];

		// 가로
		if (map[i][0] == 1 || map[i][0] == 2) {
			if (currentLength > maxWidth) {
				maxWidth = currentLength;
				maxWidthIndex = i;
			}
		}
		// 세로
		else {
			if (currentLength > maxHeight) {
				maxHeight = currentLength;
				maxHeightIndex = i;
			}
		}
	}

	int S = maxWidth * maxHeight;

	int minWidth = map[(maxHeightIndex + 3) % 6][1];
	int minHeight = map[(maxWidthIndex + 3) % 6][1];

	S -= (minWidth * minHeight);

	cout << S * K << endl;

	return 0;
}