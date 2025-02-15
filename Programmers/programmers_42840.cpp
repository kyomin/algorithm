#include <vector>
#include <algorithm>

using namespace std;

bool comp1(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second < p2.second)
		return true;
	else
		return false;
}

bool comp2(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.first < p2.first)
		return true;
	else
		return false;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	vector<pair<int, int>> v = { make_pair(1, 0), make_pair(2, 0), make_pair(3, 0) };

	int len = answers.size();

	vector<int> match1 = { 1, 2, 3, 4, 5 };
	vector<int> match2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> match3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	for (int i = 0; i < len; i++) {
		if (answers[i] == match1[i % 5])
			v[0].second += 1;

		if (answers[i] == match2[i % 8])
			v[1].second += 1;

		if (answers[i] == match3[i % 10])
			v[2].second += 1;
	}

	sort(v.begin(), v.end(), comp1);

	int MAX = v[2].second;

	vector<pair<int, int>> temp;

	temp.push_back(v[2]);

	for (int i = 1; i >= 0; i--)
		if (MAX == v[i].second)
			temp.push_back(v[i]);

	sort(temp.begin(), temp.end(), comp2);

	for (int i = 0; i < temp.size(); i++)
		answer.push_back(temp[i].first);

	return answer;
}