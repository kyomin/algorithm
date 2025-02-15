#include <iostream>
#include <string>

using namespace std;

string solution(string date) {
	string year = date.substr(0, 4);
	string month = date.substr(4, 2);
	string day = date.substr(6, 2);

	int int_month = atoi(month.c_str());
	int int_day = atoi(day.c_str());

	// '월'이 범위를 벗어나는 경우
	if (int_month < 1 || int_month > 12)
		return "-1";

	// 31일까지 '일'을 갖고 있는 경우
	if (int_month == 1 || int_month == 3 || int_month == 5 || int_month == 7 || int_month == 8 || int_month == 10 || int_month == 12) {
		if (int_day < 1 || int_day>31)
			return "-1";
	}

	// 30일까지 '일'을 갖고 있는 경우
	if (int_month == 4 || int_month == 6 || int_month == 9 || int_month == 11) {
		if (int_day < 1 || int_day>30)
			return "-1";
	}

	if (int_month == 2)
		if (int_day < 1 || int_day>28)
			return "-1";

	// 검증이 다 끝난 경우
	return year+"/"+month+"/"+day;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		cin >> str;

		cout << '#' << t << ' ' << solution(str) << '\n';
	}

	return 0;
}