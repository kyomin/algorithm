#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	vector<string> splitStrings;

	while (true) {
		int same = 0;
		int notSame = 0;		
		int targetIndex = -1;
		int len = s.length();
		char x = s[0];

		for (int i = 0; i < len; i++) {
			if (x == s[i])
				same += 1;
			else
				notSame += 1;

			if (same == notSame) {
				targetIndex = i;
				break;
			}
		}

		if (targetIndex == -1) {
			splitStrings.push_back(s);
			break;
		}

		splitStrings.push_back(s.substr(0, targetIndex + 1));
		s = s.substr(targetIndex + 1, len);

		if (s.length() == 0)
			break;
	}

	return splitStrings.size();
}