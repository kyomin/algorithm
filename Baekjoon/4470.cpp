#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	cin.get();	// 엔터키에 대한 버퍼 비움

	for (int i = 1; i <= N; i++) {
		string str;
		getline(cin, str);

		cout << to_string(i) + ". " + str << endl;
	}

	return 0;
}