#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;

	while (n >= 10) {
		int r = n % 10;

		answer.push_back(r);
		
		n /= 10;
	}

	answer.push_back(n);

	return answer;
}