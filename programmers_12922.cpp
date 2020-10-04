#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	string str = "¼ö¹Ú";

	for (int i = 0; i < n / 2; i++)
		answer += str;

	if (n % 2 == 1)
		answer += "¼ö";

	return answer;
}