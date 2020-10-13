#include <iostream>
#include <string>

using namespace std;

int main() {
	string result = "";
	string str;
	cin >> str;

	int len = str.size();
	result += str[0];

	for (int i = 1; i < len; i++)
		if (str[i] == '-')
			result += str[i + 1];

	cout << result << endl;

	return 0;
}