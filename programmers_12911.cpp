#include <string>
#include <vector>

using namespace std;

int countOne(int N) {
	int cnt = 0;

	while (N > 1) {
		int r = N % 2;
		N /= 2;

		if (r == 1) cnt++;
	}

	cnt++;

	return cnt;
}

int solution(int n) {
	int cnt = countOne(n);
	n++;

	while (true) {
		if (cnt == countOne(n)) break;

		n++;
	}

	return n;
}