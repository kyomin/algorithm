#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

int convert(string time) {
	string hh = time.substr(0, 2);
	string mm = time.substr(3);

	return ((stoi(hh) * 60) + stoi(mm));
}

vector<int> solution(vector<int> fees, vector<string> records) {
	unordered_map<string, int> intime;
	map<string, int> result;

	for (string record : records) {
		string time = record.substr(0, 5);
		string num = record.substr(6, 4);
		string inout = record.substr(11);

		if (inout == "IN") {
			intime[num] = convert(time);
		}
		else {
			result[num] += convert(time) - intime[num];
			intime.erase(num);
		}
	}

	for (auto item : intime) {
		result[item.first] += (23 * 60) + 59 - item.second;
	}

	vector<int> answer;
	for (auto item : result) {
		if (item.second <= fees[0]) {
			answer.push_back(fees[1]);
		}
		else {
			answer.push_back(fees[1] + ceil((item.second - fees[0]) / (double)fees[2])*fees[3]);
		}
	}

	return answer;
}