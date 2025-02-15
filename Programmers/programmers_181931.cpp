#include <string>
#include <vector>
using namespace std;

/*
	@param a				첫째항
	@param d				공차
	@param included				boolean 배열

	@return				included가 true인 항들인 i + 1항들만 더한 값
*/
int solution(int a, int d, vector<bool> included) {
	int answer = 0;
	int len = included.size();

	for (int i = 0; i < len; i++) {
		if (included[i])
			answer += a;

		a += d;
	}

	return answer;
}