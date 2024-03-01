#include <string>
#include <vector>
using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
	string answer = "";

	for (int i = 0; i < my_strings.size(); i++) {
		string str = my_strings[i];
		vector<int> part = parts[i];

		int s = part[0];
		int e = part[1];
		int len = e - s + 1;

		answer += str.substr(s, len);
	}

	return answer;
}