#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, vector<int> indices) {
	string answer = "";

	for (int index = 0; index < my_string.length(); index++) {
		auto iter = find(indices.begin(), indices.end(), index);

		if (iter != indices.end())
			continue;

		answer += my_string[index];
	}

	return answer;
}