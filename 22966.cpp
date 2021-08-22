#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(const pair<string, int> &p1, const pair<string, int> &p2) {
	if (p1.second < p2.second)
		return true;
	else
		return false;
}

int main() {
	vector<pair<string, int>> problems;
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string problem;
		int difficulty;
		cin >> problem >> difficulty;

		problems.push_back(make_pair(problem, difficulty));
	}

	sort(problems.begin(), problems.end(), comp);

	cout << problems[0].first << endl;

	return 0;
}