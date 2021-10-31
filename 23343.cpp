#include <iostream>
#include <string>

using namespace std;

int main() {
	bool flag = true;
	string x, y;
	cin >> x >> y;

	int len_x = x.length();
	int len_y = y.length();

	for (int i = 0; i < len_x; i++) {
		if (isalpha(x[i])) {
			flag = false;
			break;
		}
	}

	if (flag) {
		for (int i = 0; i < len_y; i++) {
			if (isalpha(y[i])) {
				flag = false;
				break;
			}
		}
	}

	if (flag)
		cout << atoi(x.c_str()) - atoi(y.c_str()) << endl;
	else
		cout << "NaN" << endl;

	return 0;
}