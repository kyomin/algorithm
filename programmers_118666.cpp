#include <string>
#include <vector>
#include <map>
using namespace std;

int getScore(int score) {
	switch (score) {
	case 1:
		return 3;
	case 2:
		return 2;
	case 3: 
		return 1;
	case 4:
		return 0;
	case 5:
		return 1;
	case 6:
		return 2;
	case 7: 
		return 3;
	}
}

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	int len = survey.size();

	string typeArr[4] = { "RT", "CF", "JM", "AN" };
	map<char, int> types;
	types.insert(make_pair('R', 0));
	types.insert(make_pair('T', 0));
	types.insert(make_pair('C', 0));
	types.insert(make_pair('F', 0));
	types.insert(make_pair('J', 0));
	types.insert(make_pair('M', 0));
	types.insert(make_pair('A', 0));
	types.insert(make_pair('N', 0));

	for (int i = 0; i < len; i++) {
		string indicator = survey[i];
		char type1 = indicator[0];
		char type2 = indicator[1];
		int choice = choices[i];

		if (choice >= 1 && choice <= 3)
			types.find(type1)->second += getScore(choice);
		
		if (choice >= 5 && choice <= 7)
			types.find(type2)->second += getScore(choice);
	}

	for (int i = 0; i < 4; i++) {
		string indicator = typeArr[i];
		char type1 = indicator[0];
		char type2 = indicator[1];
		int score1 = types.find(type1)->second;
		int score2 = types.find(type2)->second;

		if (score1 > score2)
			answer += type1;
		else if (score1 == score2)
			answer += type1;
		else
			answer += type2;
	}

	return answer;
}