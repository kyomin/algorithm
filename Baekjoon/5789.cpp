#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string str;
		cin >> str;
		int len = str.length();
		int mid = len / 2;

		if (str[mid - 1] == str[mid])
			cout << "Do-it" << endl;
		else
			cout << "Do-it-Not" << endl;
	}

	return 0;
}