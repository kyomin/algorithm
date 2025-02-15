#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<pair<int, string>> records;	// first : 시간, second : 해당 시간의 문자열 상태

// 되돌린 과거 시점의 문자열 반환
string get_past(int target_sec) {
	for (int i = records.size() - 1; i >= 0; i--)
		if (target_sec > records[i].first)
			return records[i].second;

	return "";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int n = 0; n < N; n++) {
		string cmd, val;
		int sec;

		cin >> cmd >> val >> sec;

		if (cmd == "type") {
			string push_val;

			if (records.size())
				push_val = records.back().second + val;
			else
				push_val = val;

			records.push_back({ sec, push_val });
		}
		else
			records.push_back({ sec, get_past(sec - atoi(val.c_str())) });
	}

	cout << records.back().second << '\n';

	return 0;
}