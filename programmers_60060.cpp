#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Trie {
public:
	Trie() : child(), count(0) {}	// 멤버 변수 이니셜라이저
	
	void Insert(string str) {
		Trie* curr = this;

		for (char ch : str) {
			curr->count++;

			int alphaIndex = ch - 'a';

			if (curr->child[alphaIndex] == nullptr)
				curr->child[alphaIndex] = new Trie();
			
			curr = curr->child[alphaIndex];
		}

		// for leaf node
		curr->count++;
	}

	int Search(string str) {
		Trie* curr = this;

		for (char ch : str) {
			// 다음 문자가 와일드카드일 경우
			if (ch == '?')
				return curr->count;

			int alphaIndex = ch - 'a';

			curr = curr->child[alphaIndex];

			// 다음으로 가는 문자가 없는 경우 => 검색 실패
			if (curr == nullptr)
				return 0;
		}

		// 문제 조건 상 이 경우로 오는 경우는 없긴 하다.
		// 단순히 반환 타입을 맞춰주기 위함이다.
		return curr->count;
	}

private:
	Trie* child[26];	// 26개 소문자 알파벳

	int count;	// 각 길이별 단어의 와일드카드를 탐색하지 않기 위한 메모용
};

Trie TrieRoot[10000];	// 단어 길이당 트라이 자료구조를 만들기 위함
Trie ReTrieRoot[10000];	// 와일드 카드가 접두사인 경우 뒤집어 저장할 트라이 자료구조를 위함

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (string str : words) {
		TrieRoot[str.length() - 1].Insert(str);

		reverse(str.begin(), str.end());

		ReTrieRoot[str.length() - 1].Insert(str);
	}

	for (string str : queries) {
		// 와일드카드가 접미사인 경우 => 정방향 트라이
		if (str[0] != '?') {
			answer.push_back(TrieRoot[str.length() - 1].Search(str));
		}
		// 와일드카드가 접두사인 경우 => 역방향 트라이
		else {
			reverse(str.begin(), str.end());

			answer.push_back(ReTrieRoot[str.length() - 1].Search(str));
		}
	}

	return answer;
}