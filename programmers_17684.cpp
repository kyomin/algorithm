#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> wordMap;

	for (char c = 'A'; c <= 'Z'; ++c) {
		wordMap[string(1, c)] = c - 'A' + 1;
	}

	int val = 27;
	int len = msg.length();
	int index = 0;

	while (index < len) {
		string word = "";
		bool isRegistered = false;

		for (int i = index; i < len; i++) {
			word += msg[i];

			// 등록된 단어라면
			if (wordMap.find(word) != wordMap.end())
				continue;
			
			// 등록되지 않은 단어라면 등록
			wordMap[word] = val;
			isRegistered = true;

			val++;
			string key = word.substr(0, word.length() - 1);
			answer.push_back(wordMap[key]);

			break;
		}

		if (!isRegistered) {
			answer.push_back(wordMap[word]);

			break;
		}

		index += word.length() - 1;
	}

	return answer;
}