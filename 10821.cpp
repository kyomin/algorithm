#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int len = str.size();

	int result = 0;

	for (int i = 0; i < len; i++)
		if (str[i] == ',')
			result += 1;

	cout << result+1 << endl;

	return 0;
}