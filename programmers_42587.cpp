#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<pair<int, int>> v;

	int len = priorities.size();

	// first : 값, second : 인덱스
	for (int i = 0; i < len; i++)
		v.push_back(make_pair(priorities[i], i));

	while (true) {
		int len = v.size();
		bool judge = false;

		// 마지막 하나가 남은 것이라면
		if (len == 1) {
			answer += 1;
			break;
		}

		// 하나 이상이 남은 것이라면
		for (int i = 1; i < len; i++) {
			if (v[0].first < v[i].first) {
				judge = true;
				break;
			}
		}

		// 만일 대기열 뒤에 자기보다 큰 것이 있다면
		if (judge) {

			// 맨 앞 원소 맨 뒤로 보내고
			v.push_back(v[0]);

			// front pop!
			vector<pair<int, int>>::iterator iter = v.begin();

			v.erase(iter);
		} else {
			vector<pair<int, int>>::iterator iter = v.begin();

			if (v[0].second == location) {
				answer += 1;
				break;
			} else {
				answer += 1;
				v.erase(iter);
			}
		}
	}

	return answer;
}