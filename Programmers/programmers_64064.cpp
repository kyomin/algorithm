#include <string>
#include <vector>
#include <set>

using namespace std;

vector<vector<string>> candidates;
vector<string> vc;
set<set<string>> results;
int total;

void dfs(int idx) {
	// ���� ������ ���
	if (idx == total) {
		set<string> s(vc.begin(), vc.end());

		// �ߺ� ���� ������ ���������
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

			// ���� �ĺ��� �� �� ����.
			if (userId.size() != bannedId.size())
				continue;

			// �ĺ��� �� �� �ִ��� �Ǵ��Ѵ�.
			bool judge = true;
			int len = userId.size();

			for (int i = 0; i < len; i++) {
				if (bannedId[i] == '*')
					continue;

				if (bannedId[i] == userId[i])
					continue;

				// �ٸ� ���� �ϳ��� ������
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