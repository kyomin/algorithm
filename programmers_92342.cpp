#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, vector<int> info) {
	vector<int> answer(11);
	vector<int> temp(11);
	int maxDiff = 0;

	// (1 << 10): express 11 bits (all case of ryan)
	for (int subset = 1; subset < (1 << 10); subset++) {
		// each score
		int ryan = 0;
		int apeach = 0;

		// ryan's arrow count
		int cnt = 0;
		
		for (int i = 0; i < 10; i++) {
			// case of ryan's winning
			if (subset & (1 << i)) {
				ryan += 10 - i;
				temp[i] = info[i] + 1;
				cnt += temp[i];
			}
			// case of apeach's winning
			else {
				temp[i] = 0;
				if (info[i] > 0)
					apeach += 10 - i;
			}
		}

		if (cnt > n)
			continue;

		// valid case
		temp[10] = n - cnt;

		if (ryan - apeach == maxDiff) {
			for (int i = 10; i >= 0; i--) {
				if (temp[i] > answer[i]) {
					maxDiff = ryan - apeach;
					answer = temp;
					break;
				}
				else if (temp[i] < answer[i]) {
					break;
				}
			}
		} else if (ryan - apeach > maxDiff) {
			maxDiff = ryan - apeach;
			answer = temp;
		}
	}

	// case that ryan can't win
	if (maxDiff == 0) 
		return { -1 };

	return answer;
}