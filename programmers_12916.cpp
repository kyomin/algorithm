#include <string>

using namespace std;

bool solution(string s) {
	bool answer = true;
	int count_p = 0;
	int count_y = 0;
	int len = s.size();

	for (int i = 0; i < len; i++) {
		if (s[i] == 'p' || s[i] == 'P') {
			count_p++;
			continue;
		}

		if (s[i] == 'y' || s[i] == 'Y') {
			count_y++;
			continue;
		}
	}

	if (count_p != count_y)
		answer = false;

	return answer;
}