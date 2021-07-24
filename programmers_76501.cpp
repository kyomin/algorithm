#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
	int answer = 0;
	int len = absolutes.size();

	for (int i = 0; i < len; i++) {
		int num = absolutes[i];
		bool sign = signs[i];

		if (sign)
			answer += num;
		else
			answer += (num*(-1));
	}

	return answer;
}