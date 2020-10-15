#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	vector<string> v;
	string str;
	cin >> str;

	while (str.size() != 1) {
		v.push_back(str);
		str = str.substr(1, str.size() - 1);
	}

	v.push_back(str);

	sort(v.begin(), v.end());

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i] << '\n';

	return 0;
}