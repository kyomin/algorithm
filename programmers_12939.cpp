#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

string solution(string s) {
	string answer = "";
	vector<string> v = split(s, ' ');
	vector<int> tmp;
	int len = v.size();

	for (int i = 0; i < len; i++)
		tmp.push_back(atoi(v[i].c_str()));

	answer += to_string(*min_element(tmp.begin(), tmp.end()));
	answer += " ";
	answer += to_string(*max_element(tmp.begin(), tmp.end()));

	return answer;
}