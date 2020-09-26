#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	for (int t = 0; t < 3; t++) {
		string str;
		vector<int> v;
		cin >> str;

		int curLen = 1;
		int len = str.size();

		for (int i = 1; i < len; i++) {
			if (str[i] == str[i - 1]) {
				curLen++;
			}
			else {
				v.push_back(curLen);
				curLen = 1;
			}
		}

		v.push_back(curLen);

		cout << *max_element(v.begin(), v.end()) << '\n';
	}

	return 0;
}