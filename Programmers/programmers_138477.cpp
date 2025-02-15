#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	vector<int> rank;

	for (int i = 0; i < score.size(); i++) {
		rank.push_back(score[i]);

		sort(rank.begin(), rank.end());

		if (rank.size() <= k) {
			answer.push_back(rank[0]);
			continue;
		}

		answer.push_back(rank[rank.size() - k]);
	}

	return answer;
}