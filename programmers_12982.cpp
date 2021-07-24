#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	int len = d.size();

	// ����� ���Ǹ� ���� �������� ����
	sort(d.begin(), d.end());

	for (int i = 0; i < len; i++) {
		if (d[i] > budget)
			break;

		budget -= d[i];
		answer += 1;
	}

	return answer;
}