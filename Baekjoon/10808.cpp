#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int *A = new int[26];

	for (int i = 0; i < 26; i++)
		A[i] = 0;

	int len = str.size();

	for (int i = 0; i < len; i++) {
		int n = (int)(str[i] - 97);
		A[n] += 1;
	}

	for (int i = 0; i < 26; i++)
		cout << A[i] << ' ';

	cout << endl;

	return 0;
}