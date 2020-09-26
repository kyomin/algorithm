#include <iostream>
#include <vector>

using namespace std;

int pow(int x, int y) {
	if (y == 0)
		return 1;
	
	return x * pow(x, y - 1);
}

int main() {
	int K;
	cin >> K;

	vector<int> arr;
	int len = (1 << K) - 1;

	arr.resize(len);

	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	int move = pow(2, K - 2);
	vector<int> curFloor;

	curFloor.push_back(len / 2);

	while (move != 0) {
		// 각 층의 원소 개수
		int floorLen = curFloor.size();

		for (int i = 0; i < floorLen; i++) {
			cout << arr[curFloor[i]] << ' ';
		}

		cout << '\n';

		vector<int> temp;

		for (int i = 0; i < floorLen; i++) {
			temp.push_back(curFloor[i] - move);
			temp.push_back(curFloor[i] + move);
		}

		curFloor = temp;

		move /= 2;
	}

	// 마지막 층 출력!
	int floorLen = curFloor.size();

	for (int i = 0; i < floorLen; i++) {
		cout << arr[curFloor[i]] << ' ';
	}

	return 0;
}