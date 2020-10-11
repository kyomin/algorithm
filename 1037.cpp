#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool com(int n1, int n2) {
	if (n1 < n2)
		return true;
	else
		return false;
}

int main() {
	int N;
	cin >> N;

	list<int> l;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		l.push_back(n);
	}

	int len = l.size();
	l.sort(com);

	// iterator로 리스트 원소에 접근해야 한다!
	list<int>::iterator iter;

	for (iter = l.begin(); iter != l.end(); iter++)
		v.push_back(*iter);

	if (len == 1)
		cout << v[0] * v[0] << endl;
	else
		cout << v[0] * v[len - 1] << endl;

	return 0;
}