#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	int num = atoi(str.c_str());

	// 만들 수 있는 최대 수
	sort(str.begin(), str.end());
	reverse(str.begin(), str.end());
	int end = atoi(str.c_str());
	bool found = false;
	num++;

	while (num <= end) {
		string temp = to_string(num);

		// 구성이 같은가?
		sort(temp.begin(), temp.end());
		reverse(temp.begin(), temp.end());
		if (str == temp) {
			found = true;
			break;
		}

		num++;
	}

	if (found)
		cout << num << endl;
	else
		cout << 0 << endl;

	return 0;
}