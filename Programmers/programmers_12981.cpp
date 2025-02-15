#include <string>
#include <vector>

using namespace std;

int findWordIndex(vector<string> words, string word) {
	int len = words.size();

	for (int i = 0; i < len; i++)
		if (words[i] == word)
			return i;

	return -1;
}

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	vector<string> prev_words;	// �����ձⰡ ���� �ܾ���� �ִ´�.
	int len = words.size();

	for (int i = 0; i < len; i++) {
		int cur_person = (i%n) + 1;
		int cur_turn = (i / n) + 1;
		string word = words[i];

		if (i == 0) {
			prev_words.push_back(word);
			continue;
		}

		// �ܾ ���Ե� ���
		if (findWordIndex(prev_words, word) != -1) {
			answer.push_back(cur_person);
			answer.push_back(cur_turn);
			break;
		}

		char first_char = word[0];
		char last_char = prev_words[i - 1][prev_words[i - 1].length() - 1];

		// �����ձ� ��Ģ�� ��߳� ���
		if (first_char != last_char) {
			answer.push_back(cur_person);
			answer.push_back(cur_turn);
			break;
		}

		prev_words.push_back(word);
	}

	if (answer.size() == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}