#include <string>
#include <vector>
using namespace std;

int solution(vector<string> s1, vector<string> s2) {
	int answer = 0;
	int len1 = s1.size();
	int len2 = s2.size();

	if (len1 < len2) {
		for (int i = 0; i < len1; i++) {
			string str1 = s1[i];

			for (int j = 0; j < len2; j++) {
				string str2 = s2[j];

				if (str1 == str2) {
					answer += 1;
					break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < len2; i++) {
			string str2 = s2[i];

			for (int j = 0; j < len1; j++) {
				string str1 = s1[j];

				if (str1 == str2) {
					answer += 1;
					break;
				}
			}
		}
	}

	return answer;
}