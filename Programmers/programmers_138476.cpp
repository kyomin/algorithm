#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second > b.second)
		return true;
	else
		return false;
}

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	map<int, int> save;
	vector<pair<int, int>> v;

	for (int num : tangerine) {
		if (save.find(num) != save.end()) {
			// ������ ��ϵ� ũ���� �󵵼� ����
			save[num] += 1;
		}
		else {
			// �ű� ���
			save.insert(pair<int, int>(num, 1));
		}
	}

	// map to vector
	copy(save.begin(), save.end(), back_inserter(v));

	// ����
	sort(v.begin(), v.end(), comp);

	// ������ ���� �ͺ��� ����(���� �ٸ� ũ�� ������ �ּ�ȭ �ϱ� ����)
	int index = 0;
	while (k > 0) {
		if (k <= v[index].second) {
			answer += 1;
			break;
		}
		else {
			answer += 1;
			k -= v[index].second;
		}

		index += 1;
	}

	return answer;
}