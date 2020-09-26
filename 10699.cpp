#include <stdio.h>
#include <time.h>
#include <string>

using namespace std;

int main() {
	time_t t = time(NULL);
	struct tm tm;
	localtime_s(&tm, &t);

	string year = to_string(tm.tm_year + 1900);
	string month = to_string(tm.tm_mon + 1);
	string day = to_string(tm.tm_mday);

	if (month.size() == 1) {
		month = "0" + month;
	}

	if (day.size() == 1) {
		day = "0" + day;
	}

	printf("%s-%s-%s\n", year.c_str(), month.c_str(), day.c_str());

	return 0;
}