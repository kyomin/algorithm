#include <string>
#include <vector>
using namespace std;

int solution(vector<int> common) {
	int answer = 0;
	int len = common.size();
	int d1, d2, r1, r2;

	d1 = common[1] - common[0];
	d2 = common[2] - common[1];
	r1 = common[1] / common[0];
	r2 = common[2] / common[1];

	if (d1 == d2)
		answer = common[len - 1] + d1;
	else
		answer = common[len - 1] * r1;

	return answer;
}