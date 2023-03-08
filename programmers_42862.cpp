#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	// 여벌 체육복을 가져온 학생이 체육복을 도난당한 경우
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++){
			if (lost[i] == reserve[j]) {
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				i--; j--;
			}
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] + 1 == reserve[j] || lost[i] - 1 == reserve[j]) {
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				i--; j--;
				break;
			}
		}
	}

	answer = n - lost.size();
	return answer;
}