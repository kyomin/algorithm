#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];

bool comp(const int &n1, const int &n2) {
	if (n1 > n2)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 10; i++)
			cin >> arr[i];

		sort(arr, arr + 10, comp);

		cout << arr[2] << '\n';
	}

	return 0;
}