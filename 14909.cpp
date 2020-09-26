#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

int main() {
	string str;
	getline(cin, str);

	vector<string> nums = split(str, ' ');

	int len = nums.size();
	int cnt = 0;

	for (int i = 0; i < len; i++) {
		if(atoi(nums[i].c_str()) > 0)
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}