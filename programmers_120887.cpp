#include <string>
using namespace std;

int solution(int i, int j, int k) {
	int answer = 0;
	
	for (int index = i; index <= j; index++) {
		string num = to_string(index);

		for (int index2 = 0; index2 < num.length(); index2++) {
			char ch = num[index2];

			if (k == (int)(ch - '0'))
				answer++;
		}
	}

	return answer;
}