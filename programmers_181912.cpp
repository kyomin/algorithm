#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
	vector<int> answer;

	for (string str : intStrs) {
		int num = atoi(str.substr(s, l).c_str());

		if (num > k)
			answer.push_back(num);
	}

	return answer;
}