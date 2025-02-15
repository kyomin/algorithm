#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool checkFortuneString(vector<char> arr) {
	for (int i = 0; i < arr.size() - 1; i++)
		if (arr[i] == arr[i + 1])
			return false;

	return true;
}

int main() {
	int ans = 0;
	string str;
	cin >> str;

	sort(str.begin(), str.end());
	vector<char> arr(str.begin(), str.end());

	do {
		if (checkFortuneString(arr))
			ans++;
	} while (next_permutation(arr.begin(), arr.end()));

	cout << ans << '\n';

	return 0;
}