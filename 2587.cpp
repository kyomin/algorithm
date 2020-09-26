#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int sum = 0;
	vector<int> arr;

	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		sum += n;
		arr.push_back(n);
	}

	int avg = sum / 5;

	sort(arr.begin(), arr.end());

	cout << avg << endl;
	cout << arr[2] << endl;

	return 0;
}