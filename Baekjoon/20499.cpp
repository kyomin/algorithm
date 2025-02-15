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
	string str;
	cin >> str;

	vector<string> nums = split(str, '/');

	int K = atoi(nums[0].c_str());
	int D = atoi(nums[1].c_str());
	int A = atoi(nums[2].c_str());

	if (K + A < D || D == 0)
		cout << "hasu" << endl;
	else
		cout << "gosu" << endl;

	return 0;
}