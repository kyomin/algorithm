#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	cin.get();	// ����Ű�� ���� ���� ���

	for (int i = 1; i <= N; i++) {
		string str;
		getline(cin, str);

		cout << to_string(i) + ". " + str << endl;
	}

	return 0;
}