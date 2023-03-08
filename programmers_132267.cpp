#include <string>
#include <vector>
using namespace std;

int solution(int a, int b, int n) {
	int answer = 0;
	int q;
	int r;

	while (n >= a) {
		q = (n / a)*b;
		r = n % a;
		answer += q;
		q += r;
		n = q;
	}

	return answer;
}