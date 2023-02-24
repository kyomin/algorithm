#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(string numbers) {
	map<string, string> m = {
		{"zero", "0"},
		{"one", "1"},
		{"two", "2"},
		{"three", "3"},
		{"four", "4"},
		{"five", "5"},
		{"six", "6"},
		{"seven", "7"},
		{"eight", "8"},
		{"nine", "9"}
	};
	long long answer = 0;
	string numString = "";
	int index = 0;
	int len = numbers.length();

	while (index < len) {
		// for 3 length number
		// one, two, six
		string num = numbers.substr(index, 3);

		if (m.find(num) != m.end()) {
			numString += m.find(num)->second;
			index += 3;
			continue;
		}

		// for 4 length number
		// zero, four, five, nine
		num = numbers.substr(index, 4);
		if (m.find(num) != m.end()) {
			numString += m.find(num)->second;
			index += 4;
			continue;
		}

		// for 5 length number
		// three, seven, eight
		num = numbers.substr(index, 5);
		if (m.find(num) != m.end()) {
			numString += m.find(num)->second;
			index += 5;
			continue;
		}
	}

	answer = atoll(numString.c_str());

	return answer;
}