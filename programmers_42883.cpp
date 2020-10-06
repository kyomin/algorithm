#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int len = number.size();
	int boundary = k;
	int start = 0;

	while (boundary < len) {
		string tmp = number.substr(start, boundary - start + 1);
		sort(tmp.begin(), tmp.end());
		reverse(tmp.begin(), tmp.end());
		char target = tmp[0];

		for (int i = start; i <= boundary; i++) {
			if (target == number[i]) {
				answer += number[i];
				start = i + 1;
				boundary += 1;
				k--;
				break;
			}
		}
	}

	return answer;
}