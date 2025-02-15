#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

bool comp(const string &s1, const string &s2) {
	if (s1[idx] < s2[idx])
		return true;
	else if (s1[idx] == s2[idx]) {
		if (s1 < s2)
			return true;
		else
			return false;
	}
	else
		return false;
}

vector<string> solution(vector<string> strings, int n) {
	idx = n;
	sort(strings.begin(), strings.end(), comp);

	return strings;
}