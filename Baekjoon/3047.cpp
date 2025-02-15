#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[3];

int main() {
	string str;

	for (int i = 0; i < 3; i++)
		cin >> arr[i];

	cin >> str;

	sort(arr, arr + 3);

	for (int i = 0; i < 3; i++)
		if (str[i] == 'A')
			cout << arr[0] << ' ';
		else if (str[i] == 'B')
			cout << arr[1] << ' ';
		else
			cout << arr[2] << ' ';

	return 0;
}