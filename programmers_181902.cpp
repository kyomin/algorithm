#include <string>
#include <vector>
#include <cctype>
using namespace std;

vector<int> solution(string my_string) {
	vector<int> answer(52, 0);

	for (char alpha : my_string) {
		int index;

		if (isupper(alpha))
			index = (int)(alpha - 'A');
		else
			index = (int)(alpha - 'a') + 26;

		answer[index]++;
	}

	return answer;
}