#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const int& a, const int& b) {
	if (a > b)
		return true;
	else
		return false;
}

int solution(int k, int m, vector<int> score) {
	int answer = 0;
	int len = score.size();
	sort(score.begin(), score.end(), comp);

	for (int i = m - 1; i < len; i += m) {
		int num = score[i];
		answer += (num*m);
	}

	return answer;
}