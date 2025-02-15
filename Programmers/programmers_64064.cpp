#include <string>
#include <vector>
#include <set>

using namespace std;

vector<vector<string>> candidates;
vector<string> vc;
set<set<string>> results;
int total;

void dfs(int idx) {
	// 끝에 도달한 경우
	if (idx == total) {
		set<string> s(vc.begin(), vc.end());

		// 중복 없이 조합이 만들어지면
		if (s.size() == total)
			results.insert(s);

		return;
	}

	for (int i = 0; i < candidates[idx].size(); i++) {
		vc.push_back(candidates[idx][i]);

		dfs(idx + 1);

		vc.pop_back();
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	total = banned_id.size();

	int bannedLen = banned_id.size();
	int userLen = user_id.size();

	for (int banned = 0; banned < bannedLen; banned++) {
		string bannedId = banned_id[banned];
		vector<string> bannedCandidate;

		for (int user = 0; user < userLen; user++) {
			string userId = user_id[user];

			// 차단 후보가 될 수 없다.
			if (userId.size() != bannedId.size())
				continue;

			// 후보가 될 수 있는지 판단한다.
			bool judge = true;
			int len = userId.size();

			for (int i = 0; i < len; i++) {
				if (bannedId[i] == '*')
					continue;

				if (bannedId[i] == userId[i])
					continue;

				// 다른 것이 하나라도 있으면
				judge = false;
				break;
			}

			if (judge)
				bannedCandidate.push_back(userId);
		}

		candidates.push_back(bannedCandidate);
	}

	dfs(0);

	answer = results.size();

	return answer;
}