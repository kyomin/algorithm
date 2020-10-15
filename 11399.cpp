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

	// �޸� ���� �迭
	int *D = new int[N];

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	// ���Ϳ� ��� ���� ������ ����Ʈ�� ����!
	for (auto iter = v.begin(); iter != v.end(); iter++)
		l.push_back(*iter);

	l.sort(com);
	v.clear();

	for (auto i = l.begin(); i != l.end(); i++)
		v.push_back(*i);

	// �ʱ�ȭ
	D[0] = v[0];

	for (int i = 1; i < N; i++)
		D[i] = v[i] + D[i - 1];

	for (int i = 0; i < N; i++)
		sum += D[i];

	cout << sum << endl;

	return 0;
}