#include <iostream>
#include <string>
using namespace std;

int main() {
	int ans = 1;
	int d = 10;
	int c = 26;
	int cntD = 0;
	int cntC = 0;
	string str;
	cin >> str;

	int len = str.length();
	for (int i = 0; i < len; i++) {
		char ch = str[i];

		if (ch == 'd') {
			if (cntC > 0) {
				cntC = 0;
				c = 26;
			}

			ans *= d;

			if(cntD == 0)
				d--;

			cntD++;
		}
		else {
			if (cntD > 0) {
				cntD = 0;
				d = 10;
			}

			ans *= c;

			if (cntC == 0)
				c--;

			cntC++;
		}
	}

	cout << ans << endl;

	return 0;
}