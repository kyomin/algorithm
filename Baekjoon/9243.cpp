#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string before, current;
	cin >> n;
	cin >> before >> current;

	// n이 짝수라면 원복이 되므로
	if (n % 2 == 0) {
		if(before == current)
			cout << "Deletion succeeded" << endl;
		else
			cout << "Deletion failed" << endl;

		return 0;
	}

	int len = before.length();
	bool flag = true;

	for (int i = 0; i < len; i++) {
		char before_bit = before[i];
		char cur_bit = current[i];

		if (before_bit == cur_bit) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "Deletion succeeded" << endl;
	else
		cout << "Deletion failed" << endl;
}