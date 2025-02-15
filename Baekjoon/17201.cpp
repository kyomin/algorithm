#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string magnets;
	cin >> N;
	cin >> magnets;

	bool flag = true;
	int len = magnets.length();
	
	for (int i = 1; i < (len - 1); i += 2) {
		if (magnets[i] == magnets[i + 1]) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}