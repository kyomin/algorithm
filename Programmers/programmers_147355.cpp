#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
	int answer = 0;
	int len_t = t.length();
	int len_p = p.length();
	int end = len_t - len_p;
	int intP = atoi(p.c_str());

	for (int start = 0; start <= end; start++) {
		string subStr = t.substr(start, len_p);
		bool flag = true;

		for (int i = 0; i < len_p; i++) {
			int a = (int)(subStr[i] - '0');
			int b = (int)(p[i] - '0');

			if (a < b)
				break;
			else if (a == b)
				continue;
			else
				flag = false;
		}

		if (flag)
			answer++;
	}

	return answer;
}