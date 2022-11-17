#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;
	int wantLen = want.size();
	int len = discount.size();

	for (int i = 0; i + 10 <= len; i++) {
		map<string, int> m;

		for (int j = i; j < i + 10; j++) {
			string product = discount[j];

			// 해당 키를 못 찾았다면
			if (m.find(product) == m.end())
				m[product] = 1;
			// 해당 키를 찾았다면
			else
				m.find(product)->second += 1;	// 개수 증가
		}

		bool flag = true;

		for (int j = 0; j < wantLen; j++) {
			string product = want[j];

			// 할인하는 날이 없는 경우
			if (m.find(product) == m.end()) {
				flag = false;
				break;
			}

			// 원하는 제품과 수량이 일치하지 않는 경우
			if (m.find(product)->second < number[j]) {
				flag = false;
				break;
			}
		}

		if (flag)
			answer++;
	}

	return answer;
}