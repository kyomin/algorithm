#include <iostream>
#include <string>

using namespace std;

typedef struct {
	int hour;
	int minute;
	int second;
}Time;

Time setTime(string time) {
	return Time{
		stoi(time.substr(0, 2)),
		stoi(time.substr(3, 2)),
		stoi(time.substr(6, 2))
	};
}

void printTime(Time time) {
	string hour = to_string(time.hour);
	string minute = to_string(time.minute);
	string second = to_string(time.second);

	hour = hour.length() == 1 ? '0' + hour : hour;
	minute = minute.length() == 1 ? '0' + minute : minute;
	second = second.length() == 1 ? '0' + second : second;

	cout << hour << ":" << minute << ":" << second << "\n";
}

int main(void) {
	string currentTime, startTime;
	cin >> currentTime >> startTime;

	Time current = setTime(currentTime);
	Time start = setTime(startTime);

	Time result;
	result.second = start.second - current.second;

	if (result.second < 0) {
		result.second += 60;
		start.minute--;
	}

	result.minute = start.minute - current.minute;

	if (result.minute < 0) {
		result.minute += 60;
		start.hour--;
	}

	result.hour = start.hour - current.hour;

	if (result.hour < 0)
		result.hour += 24;

	printTime(result);

	return 0;
}