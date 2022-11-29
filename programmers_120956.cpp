#include <string>
#include <vector>
#include <map>
using namespace std;

string pronunciations[4] = { "aya", "ye", "woo", "ma" };
bool visit[4];
map<string, bool> m;
vector<string> vc;

void dfs(int cnt) {
	if (vc.size() == cnt) {
		string temp = "";

		for (auto i : vc)
			temp += i;
		
		m.insert(make_pair(temp, true));

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!visit[i]) {
			visit[i] = true;
			vc.push_back(pronunciations[i]);

			dfs(cnt);

			vc.pop_back();
			visit[i] = false;
		}
	}
}

int solution(vector<string> babbling) {
	int answer = 0;
	int len = babbling.size();

	for (int i = 1; i <= 4; i++)
		dfs(i);

	for (int i = 0; i < len; i++) {
		string pronunciation = babbling[i];

		if (m.find(pronunciation) == m.end())
			continue;

		answer++;
	}

	return answer;
}