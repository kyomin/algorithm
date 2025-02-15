#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// int -> string convert function
string intToString(int n) {
	stringstream s;
	s << n;
	return s.str();
}

int d(string str) {
	int len = str.size();
	int sum = 0;

	for (int i = 0; i < len; i++)
		sum += (int)(str[i] - '0');

	sum += atoi(str.c_str());

	return sum;
}

int main() {
	// ���� ������� ���� ����!
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// �ε��� 10000������ �迭 �����Ҵ�!
	int *A = new int[10001];

	// �迭�� ���� ��� 1�� �ʱ�ȭ!
	for (int i = 1; i <= 10000; i++)
		A[i] = 1;

	for (int i = 1; i <= 10000; i++) {
		string s = intToString(i);

		// �����ѹ��� �ƴ� ���� ���ϵǹǷ�
		int idx = d(s);

		// �ε��� ���� ���� ������
		if (idx <= 10000)
			// 0(false)�� �ٲ��ش�.
			A[idx] = 0;
	}

	// ���� �۾��� �� �������� ���� �ѹ��� ���� ���!
	for (int i = 1; i <= 10000; i++)
		if (A[i] == 1)
			cout << i << '\n';

	return 0;
}