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
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string problem;
		cin >> problem;

		if (problem == "P=NP") {
			cout << "skipped" << endl;
			continue;
		}

		vector<string> nums = split(problem, '+');
		int sum = atoi(nums[0].c_str()) + atoi(nums[1].c_str());

		cout << sum << endl;
	}

	return 0;
}