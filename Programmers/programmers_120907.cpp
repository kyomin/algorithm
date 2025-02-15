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

int operate(int a, int b, char oper) {
	switch (oper) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	}
}

vector<string> solution(vector<string> quiz) {
	vector<string> answer;
	int len = quiz.size();

	for (int i = 0; i < len; i++) {
		string str = quiz[i];
		vector<string> dividedStr = split(str, ' ');

		string a = dividedStr[0];
		string oper = dividedStr[1];
		string b = dividedStr[2];
		string ans = dividedStr[4];

		int result = operate(atoi(a.c_str()), atoi(b.c_str()), oper[0]);

		if (atoi(ans.c_str()) == result)
			answer.push_back("O");
		else
			answer.push_back("X");
	}

	return answer;
}