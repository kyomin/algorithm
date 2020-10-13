#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;

	}

	return a;
}

void SPLIT(vector<string>& v, string str, char token) {
	int start = 0;
	int len = str.size();

	for (int i = 0; i < len; i++) {
		// 만일 문자열의 처음부터 토큰 문자를 만나면 아무것도 하지 않는다. 
		if (i == 0 && str[i] == token) {
			start = i + 1;
			continue;
		}

		// 문자열의 끝이라면
		if (i == len - 1)
			v.push_back(str.substr(start, i + 1));
		else if (str[i] == token) {
			v.push_back(str.substr(start, i));
			start = i + 1;
		}
	}
}

int main() {
	int t;
	cin >> t;

	cin.ignore();

	for (int i = 0; i < t; i++) {
		vector<string> vec;
		vector<int> int_vector;
		string str;

		// 공백까지 포함하여 string 변수에 입력!
		getline(cin, str);
		SPLIT(vec, str, ' ');

		int start = 1;
		int iter = 2;
		unsigned long sum = 0;
		int len = vec.size();

		// 벡터의 각 요소에 대해 string -> int 변환 작업!
		for (int i = 0; i < len; i++)
			int_vector.push_back(atoi(vec[i].c_str()));

		while (start != len - 1) {
			for (int i = iter; i < len; i++)
				sum += GCD(int_vector[start], int_vector[i]);

			iter += 1;
			start += 1;
		}

		cout << sum << endl;
	}

	return 0;
}