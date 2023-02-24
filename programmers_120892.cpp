#include <string>
#include <vector>
using namespace std;

string solution(string cipher, int code) {
	string answer = "";
	int index = code - 1;	// start index
	int len = cipher.length();

	while (index < len) {
		answer += cipher[index];
		index += code;
	}

	return answer;
}