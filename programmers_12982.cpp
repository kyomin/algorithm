#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	int len = d.size();

	// 계산의 편의를 위해 오름차순 정렬
	sort(d.begin(), d.end());

	for (int i = 0; i < len; i++) {
		if (d[i] > budget)
			break;

		budget -= d[i];
		answer += 1;
	}

	return answer;
}