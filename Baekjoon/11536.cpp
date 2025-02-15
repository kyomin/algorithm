#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(const string &s1, const string &s2) {
	if (s1 > s2)
		return true;
	else
		return false;
}

int main() {
	vector<string> names;
	vector<string> incresing_names;
	vector<string> decreasing_names;
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string name;
		cin >> name;

		names.push_back(name);
		incresing_names.push_back(name);
		decreasing_names.push_back(name);
	}

	sort(incresing_names.begin(), incresing_names.end());
	sort(decreasing_names.begin(), decreasing_names.end(), desc);

	bool increase_flag = true;
	bool decrease_flag = true;

	for (int n = 0; n < N; n++) {
		if (names[n] != incresing_names[n]) {
			increase_flag = false;
			break;
		}
	}

	for (int n = 0; n < N; n++) {
		if (names[n] != decreasing_names[n]) {
			decrease_flag = false;
			break;
		}
	}

	if (increase_flag)
		cout << "INCREASING" << endl;
	else if(decrease_flag)
		cout << "DECREASING" << endl;
	else
		cout << "NEITHER" << endl;

	return 0;
}