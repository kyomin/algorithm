#include <string>
#include <vector>
using namespace std;

int checkX[10];
int checkY[10];

string solution(string X, string Y) {
	string answer = "";	
	int lenX = X.length();
	int lenY = Y.length();

	for (int i = 0; i < lenX; i++) {
		int num = (int)(X[i] - '0');

		checkX[num]++;
	}

	for (int i = 0; i < lenY; i++) {
		int num = (int)(Y[i] - '0');

		checkY[num]++;
	}

	for (int i = 9; i >= 0; i--) {
		if (checkX[i] == 0 || checkY[i] == 0)
			continue;

		if (checkX[i] < checkY[i]) {
			for (int j = 0; j < checkX[i]; j++)
				answer += to_string(i);
		}
		else {
			for (int j = 0; j < checkY[i]; j++)
				answer += to_string(i);
		}
	}

	if (answer.length() == 0)
		return "-1";
	else if (answer[0] == '0')
		return "0";
	else
		return answer;
}