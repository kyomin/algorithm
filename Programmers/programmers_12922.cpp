#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	string str = "����";

	for (int i = 0; i < n / 2; i++)
		answer += str;

	if (n % 2 == 1)
		answer += "��";

	return answer;
}