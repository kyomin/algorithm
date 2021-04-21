#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> food_map[11];
int max_cnt[11];

// 0 ~ length까지 길이의 문자열 조합 만들기
void comb(string str, int pos, string candidate) {
	// 인덱스를 넘어서면 조합이 만들어진 것이다.
	if (pos >= str.length()) {
		// 길이 2 이상의 조합에 대해서만 판단한다.
		int len = candidate.length();
		if (len >= 2) {
			// 아직 등록되지 않은 조합인 경우
			if (food_map[len].find(candidate) == food_map[len].end())
				food_map[len][candidate] = 1;
			else
				food_map[len].find(candidate)->second += 1;

			max_cnt[len] = max(max_cnt[len], food_map[len].find(candidate)->second);
		}

		return;
	}

	comb(str, pos + 1, candidate + str[pos]);
	comb(str, pos + 1, candidate);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (string order : orders) {
		sort(order.begin(), order.end());
		comb(order, 0, "");
	}

	for (int num : course) {
		int cur_max_cnt = max_cnt[num];

		// 최소 2명 이상의 손님에게서 주문된 구성만 코스요리 후보에 들어간다.
		for (auto it = food_map[num].begin(); it != food_map[num].end(); it++)
			if (it->second >= 2 && it->second == cur_max_cnt)
				answer.push_back(it->first);
	}

	sort(answer.begin(), answer.end());

	return answer;
}