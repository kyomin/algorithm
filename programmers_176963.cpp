#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
	vector<int> answer;
	map<string, int> m;
	int len = name.size();

	for (int i = 0; i < len; i++)
		m.insert(make_pair(name[i], yearning[i]));

	for (vector<string> names : photo) {
		int score = 0;

		for (string name : names) {
			if (m.find(name) == m.end())
				continue;

			score += m.find(name)->second;
		}

		answer.push_back(score);
	}

	return answer;
}