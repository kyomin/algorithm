#include <string>
#include <vector>
using namespace std;

int alphas[26];

string solution(string s) {
	string answer = "";
	int len = s.length();

	for (int i = 0; i < len; i++) {
		char alpha = s[i];
		int idx = (int)(alpha - 'a');
		alphas[idx]++;
	}

	for (int i = 0; i < 26; i++) 
		if (alphas[i] == 1) 
			answer += (char)(97 + i);		

	return answer;
}