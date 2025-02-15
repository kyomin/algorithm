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

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	string str;
	cin >> str;

	vector<string> nums = split(str, ':');
	int a = atoi(nums[0].c_str());
	int b = atoi(nums[1].c_str());
	int g = gcd(a, b);

	a /= g;
	b /= g;
	string ans = to_string(a) + ":" + to_string(b);
	cout << ans << endl;

	return 0;
}