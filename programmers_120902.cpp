#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

int getCalcResult(int a, int b, char oper) {
	switch (oper) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	}	
}

int solution(string my_string) {
	int answer = 0;
	vector<string> mathematics = split(my_string, ' ');
	vector<int> operands;
	char oper;
	int len = mathematics.size();

	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			operands.push_back(atoi(mathematics[i].c_str()));

			if (operands.size() == 2) {
				int result = getCalcResult(operands[0], operands[1], oper);
				operands.clear();
				operands.push_back(result);
			}
		}
		else {
			oper = mathematics[i][0];
		}
	}

	answer = operands[0];
	return answer;
}