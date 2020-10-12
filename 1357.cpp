#include <iostream>
#include <string>

using namespace std;

int Rev(int n) {
	string result = "";
	string str = to_string(n);
	int len = str.size();
	int idx = -1;

	for (int i = len - 1; i >= 0; i--) {
		if (str[i] != '0') {
			idx = i;
			break;
		}
	}

	if (idx == -1)
		return 0;

	for (int i = idx; i >= 0; i--)
		result += str[i];

	return atoi(result.c_str());
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	cout << Rev(Rev(n1) + Rev(n2)) << endl;

	return 0;
}