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
			else           // 문자가 같으면 계속 for문을 돈다.
				continue;
		}
	}
}

int main() {
	int N;
	cin >> N;

	set<string> s;   // 중복된 단어 제거를 위해 set을 사용

	for (int n = 0; n < N; n++) {
		string word;
		cin >> word;
		s.insert(word);
	}

	list<string> l;   // sort를 위해 list 사용
	set<string>::iterator i;  // set, list, vector형 포인터 자료형이라 생각!
	int k = 0;

	for (i = s.begin(); i != s.end(); i++)
		l.push_back(*i);

	l.sort(com);

	list<string>::iterator t;

	for (t = l.begin(); t != l.end(); t++)
		cout << *t << endl;

	return 0;
}