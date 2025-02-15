#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
	sort(s.begin(), s.end());		// 오름차 정렬 후
	reverse(s.begin(), s.end());	// 뒤집기

	return s;
}