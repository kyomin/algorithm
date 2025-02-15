#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long square_n = 1;
	bool found = true;

	while (true) {
		if (square_n*square_n == n) {
			square_n++;
			answer = square_n * square_n;
			break;
		}

		if (square_n*square_n > n) {
			found = false;
			break;
		}

		square_n++;
	}

	if (!found) return -1;

	return answer;
}