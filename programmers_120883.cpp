#include <string>
#include <vector>
using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
	string answer = "fail";
	string id = id_pw[0];
	string pw = id_pw[1];

	for (auto row : db) {
		string db_id = row[0];
		string db_pw = row[1];

		if (id == db_id && pw == db_pw) {
			answer = "login";
			break;
		}

		if (id == db_id && pw != db_pw) {
			answer = "wrong pw";
			break;
		}
	}

	return answer;
}