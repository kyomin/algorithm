#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Trie {
public:
	Trie() : child(), count(0) {}	// ��� ���� �̴ϼȶ�����
	
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
			// ���� ���ڰ� ���ϵ�ī���� ���
			if (ch == '?')
				return curr->count;

			int alphaIndex = ch - 'a';

			curr = curr->child[alphaIndex];

			// �������� ���� ���ڰ� ���� ��� => �˻� ����
			if (curr == nullptr)
				return 0;
		}

		// ���� ���� �� �� ���� ���� ���� ���� �ϴ�.
		// �ܼ��� ��ȯ Ÿ���� �����ֱ� �����̴�.
		return curr->count;
	}

private:
	Trie* child[26];	// 26�� �ҹ��� ���ĺ�

	int count;	// �� ���̺� �ܾ��� ���ϵ�ī�带 Ž������ �ʱ� ���� �޸��
};

Trie TrieRoot[10000];	// �ܾ� ���̴� Ʈ���� �ڷᱸ���� ����� ����
Trie ReTrieRoot[10000];	// ���ϵ� ī�尡 ���λ��� ��� ������ ������ Ʈ���� �ڷᱸ���� ����

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (string str : words) {
		TrieRoot[str.length() - 1].Insert(str);

		reverse(str.begin(), str.end());

		ReTrieRoot[str.length() - 1].Insert(str);
	}

	for (string str : queries) {
		// ���ϵ�ī�尡 ���̻��� ��� => ������ Ʈ����
		if (str[0] != '?') {
			answer.push_back(TrieRoot[str.length() - 1].Search(str));
		}
		// ���ϵ�ī�尡 ���λ��� ��� => ������ Ʈ����
		else {
			reverse(str.begin(), str.end());

			answer.push_back(ReTrieRoot[str.length() - 1].Search(str));
		}
	}

	return answer;
}