#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, string> table;

// base : 몇 진수인가?, num : 바꾸고자 하는 수
string makeBase(int base, int num) {
	string str = "";

	while (num >= base) {
		int r = num % base;

		if (r >= 10)
			str += table.find(r)->second;
		else
			str += to_string(r);

		num /= base;
	}

	if (num >= 10)
		str += table.find(num)->second;
	else
		str += to_string(num);

	reverse(str.begin(), str.end());

	return str;
}

string solution(int n, int t, int m, int p) {
	table[10] = "A";
	table[11] = "B";
	table[12] = "C";
	table[13] = "D";
	table[14] = "E";
	table[15] = "F";

	string answer = "";
	string tmp = "";
	int num = 0;
	int boundary = p + m * (t - 1);		// 여기 길이까지만 만들면 된다.

	while (tmp.size() <= boundary) {
		tmp += makeBase(n, num);

		num++;
	}

	for (int i = 0; i < t; i++) {
		int idx = (p + (m*i)) - 1;
		answer += tmp[idx];
	}

	return answer;
}