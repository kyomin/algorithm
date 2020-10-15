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
	vector<int> v;
	list<int> l;
	int sum = 0;
	int N;
	cin >> N;

	// 메모를 위한 배열
	int *D = new int[N];

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	// 벡터에 담긴 내용 고스란히 리스트에 저장!
	for (auto iter = v.begin(); iter != v.end(); iter++)
		l.push_back(*iter);

	l.sort(com);
	v.clear();

	for (auto i = l.begin(); i != l.end(); i++)
		v.push_back(*i);

	// 초기화
	D[0] = v[0];

	for (int i = 1; i < N; i++)
		D[i] = v[i] + D[i - 1];

	for (int i = 0; i < N; i++)
		sum += D[i];

	cout << sum << endl;

	return 0;
}