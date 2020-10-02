#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int A, B;

	if (str.size() == 2) {
		A = (int)(str[0] - '0');
		B = (int)(str[1] - '0');
	}
	else if (str.size() == 3 && str[2]=='0') {
		A = atoi(str.substr(0, 1).c_str());
		B = atoi(str.substr(1, 2).c_str());
	}
	else if (str.size() == 3 && str[2] != '0') {
		A = atoi(str.substr(0, 2).c_str());
		B = atoi(str.substr(2, 2).c_str());
	}
	else if(str.size() == 4){
		A = atoi(str.substr(0, 2).c_str());
		B = atoi(str.substr(2, 2).c_str());
	}

	cout << A + B << endl;
	
	return 0;
}