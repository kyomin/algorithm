#include <string>
#include <vector>

using namespace std;

int calcNumOfFactors(int n) {
	int ret = 0;

	for (int i = 2; i <= (n / 2); i++)
		if (n%i == 0)
			ret += 1;
	
	return ret;
}

int solution(int left, int right) {
	int answer = 0;

	for (int i = left; i <= right; i++) {
		if (i == 1) {
			answer -= 1;
			continue;
		}

		int num_of_factors = calcNumOfFactors(i);

		if (num_of_factors % 2 == 0)
			answer += i;
		else
			answer -= i;
	}

	return answer;
}