#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string password;
		cin >> password;

		if (password.length() < 6 || password.length() > 9)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}

	return 0;
}