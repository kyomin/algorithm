#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> food_map[11];
int max_cnt[11];

// 0 ~ length���� ������ ���ڿ� ���� �����
void comb(string str, int pos, string candidate) {
	// �ε����� �Ѿ�� ������ ������� ���̴�.
	if (pos >= str.length()) {
		// ���� 2 �̻��� ���տ� ���ؼ��� �Ǵ��Ѵ�.
		int len = candidate.length();
		if (len >= 2) {
			// ���� ��ϵ��� ���� ������ ���
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

		// �ּ� 2�� �̻��� �մԿ��Լ� �ֹ��� ������ �ڽ��丮 �ĺ��� ����.
		for (auto it = food_map[num].begin(); it != food_map[num].end(); it++)
			if (it->second >= 2 && it->second == cur_max_cnt)
				answer.push_back(it->first);
	}

	sort(answer.begin(), answer.end());

	return answer;
}