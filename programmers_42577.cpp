#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	int len = phone_book.size();

	for (int i = 0; i < len; i++) {
		string s1 = phone_book[i];

		for (int j = 0; j < len; j++) {
			string s2 = phone_book[j];

			// 자기 자신은 제외한다.
			if (s1 == s2)
				continue;

			if (s1.size() > s2.size()) {
				if (s2 == s1.substr(0, s2.size()))
					return false;
			}
		}
	}

	return answer;
}