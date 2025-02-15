#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const pair<string, int> &p1, const pair<string, int> &p2) {
	if (p1.first < p2.first)
		return true;
	else
		return false;
}

string getNumStr(char n) {
	if (n == '0')
		return "zero";
	else if (n == '1')
		return "one";
	else if (n == '2')
		return "two";
	else if (n == '3')
		return "three";
	else if (n == '4')
		return "four";
	else if (n == '5')
		return "five";
	else if (n == '6')
		return "six";
	else if (n == '7')
		return "seven";
	else if (n == '8')
		return "eight";
	else if (n == '9')
		return "nine";
}

int main() {
	vector<pair<string, int>> nums;
	int M, N;
	cin >> M >> N;

	for (int n = M; n <= N; n++) {
		string str = "";
		string str_n = to_string(n);
		int len = str_n.length();

		for (int i = 0; i < len; i++)
			str += getNumStr(str_n[i]);

		nums.push_back(make_pair(str, n));
	}

	sort(nums.begin(), nums.end(), comp);

	int size = nums.size();
	for (int i = 0; i < size; i++) {
		cout << nums[i].second;

		if ((i + 1) % 10 == 0)
			cout << endl;
		else
			cout << ' ';
	}
	
	return 0;
}