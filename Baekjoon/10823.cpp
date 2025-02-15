#include <iostream>
#include <vector>
#include <string>
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
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str = "";
	string temp;

	while (cin>>temp) {
		str += temp;
	}

	vector<string> nums = split(str, ',');

	int ans = 0;

	int len = nums.size();

	for (int i = 0; i < len; i++)
		ans += atoi(nums[i].c_str());

	cout << ans << '\n';

	return 0;
}