#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<string> v;

	while (true) {
		string str;

		getline(cin, str);

		if (str == "END")
			break;

		v.push_back(str);
	}

	int len = v.size();

	for (int i = 0; i < len; i++) {
		reverse(v[i].begin(), v[i].end());

		cout << v[i] << '\n';
	}

	return 0;
}