#include <string>
#include <sstream>
#include <vector>
#include <map>
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

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	
	string todayWithoutDot = "";
	for (int i = 0; i < today.length(); i++) {
		if (today[i] == '.')
			continue;

		todayWithoutDot += today[i];
	}
	int intToday = atoi(todayWithoutDot.c_str());

	map<string, int> termsMap;
	for (string term : terms) {
		vector<string> splitTerm = split(term, ' ');
		string termType = splitTerm[0];
		int expirationDate = atoi(splitTerm[1].c_str());

		termsMap.insert(make_pair(termType, expirationDate));
	}

	for (int i = 0; i < privacies.size(); i++) {
		string privacy = privacies[i];
		vector<string> splitPrivacy = split(privacy, ' ');
		string collectionDate = splitPrivacy[0];
		string termType = splitPrivacy[1];
		int expirationDate = termsMap.find(termType)->second;

		vector<string> splitCollectionDate = split(collectionDate, '.');
		int year = atoi(splitCollectionDate[0].c_str());
		int month = atoi(splitCollectionDate[1].c_str());
		int date = atoi(splitCollectionDate[2].c_str());

		int addYear = expirationDate / 12;
		year += addYear;
		month += expirationDate % 12;

		if (month > 12) {
			year += (month / 12);
			month = month % 12;
		}

		string stringYear = to_string(year);
		string stringMonth = to_string(month);
		string stringDate = to_string(date);

		if (stringMonth.length() == 1)
			stringMonth = "0" + stringMonth;

		if (stringDate.length() == 1)
			stringDate = "0" + stringDate;

		string targetDate = stringYear + stringMonth + stringDate;
		int intTargetDate = atoi(targetDate.c_str());

		if (intToday >= intTargetDate)
			answer.push_back(i + 1);
	}

	return answer;
}