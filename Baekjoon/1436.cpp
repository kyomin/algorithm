#include <iostream>
#include <string>

using namespace std;

bool targetFind(string str, string target) {
	for (int i = 0; i < str.size(); i++)
		if (str.substr(i, 3) == target)
			return true;

	return false;
}

int main() {
	int n;
	int cnt = 0;
	int title = 666;
	string s;

	cin >> n;

	while (true) {
		s = to_string(title);

		if (targetFind(s, "666"))
			cnt += 1;

		if (cnt == n) {
			cout << title << '\n';
			break;
		}

		title++;
	}

	return 0;
}