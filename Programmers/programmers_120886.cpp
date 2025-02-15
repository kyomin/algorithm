#include <string>
#include <algorithm>
using namespace std;

int solution(string before, string after) {
	int answer = 0;
	sort(before.begin(), before.end());
	sort(after.begin(), after.end());

	answer = before == after ? 1 : 0;

	return answer;
}