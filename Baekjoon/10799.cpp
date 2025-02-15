#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> v;
	int result = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			v.push_back(i);
		else if (str[i] == ')') {
			if (i - 1 == v[v.size() - 1]) {
				v.pop_back();
				result += v.size();
			}
			else {
				v.pop_back();
				result += 1;
			}
		}
	}

	cout << result << '\n';

	return 0;
}