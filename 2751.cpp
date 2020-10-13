#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool com(int n1, int n2) {
	if (n1 < n2)
		return true;
	else
		return false;
}

int main() {
	int N;
	vector<int> v;
	list<int> l;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	for (auto iter = v.begin(); iter != v.end(); iter++)
		l.push_back(*iter);

	l.sort(com);

	for (auto i = l.begin(); i != l.end(); i++)
		cout << *i << '\n';

	cout << '\n';

	return 0;
}