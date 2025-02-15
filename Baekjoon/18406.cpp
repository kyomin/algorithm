#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int len = str.size();
	int left = 0;
	int right = 0;

	// calc left
	for (int i = 0; i < len / 2; i++)
		left += (int)(str[i] - '0');

	// calc right
	for (int i = len / 2; i < len; i++)
		right += (int)(str[i] - '0');

	if (left == right)
		cout << "LUCKY" << '\n';
	else
		cout << "READY" << '\n';

	return 0;
}