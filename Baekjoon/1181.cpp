#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>

using namespace std;

bool com(string s1, string s2) {
	if (s1.length() < s2.length())
		return true;
	else if (s1.length() > s2.length())
		return false;
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1.at(i) < s2.at(i))
				return true;
			else if (s1.at(i) > s2.at(i))
				return false;
			else           // ���ڰ� ������ ��� for���� ����.
				continue;
		}
	}
}

int main() {
	int N;
	cin >> N;

	set<string> s;   // �ߺ��� �ܾ� ���Ÿ� ���� set�� ���

	for (int n = 0; n < N; n++) {
		string word;
		cin >> word;
		s.insert(word);
	}

	list<string> l;   // sort�� ���� list ���
	set<string>::iterator i;  // set, list, vector�� ������ �ڷ����̶� ����!
	int k = 0;

	for (i = s.begin(); i != s.end(); i++)
		l.push_back(*i);

	l.sort(com);

	list<string>::iterator t;

	for (t = l.begin(); t != l.end(); t++)
		cout << *t << endl;

	return 0;
}