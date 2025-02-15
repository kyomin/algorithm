#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const int &n1, const int &n2) {
	if (n1 >= n2)
		return true;
	else
		return false;
}

int solution(vector<int> citations) {
	int len = citations.size();

	sort(citations.begin(), citations.end(), comp);

	int index = 0;

	while (index < len) {
		if (index >= citations[index])
			break;

		index++;
	}

	return index;
}