#include <iostream>
#include <string>

using namespace std;

int main() {
	int len;
	string str;
	int num_of_e = 0;
	int num_of_2 = 0;

	cin >> len;
	cin >> str;

	for (int i = 0; i < len; i++) {
		if (str[i] == 'e')
			num_of_e++;
		else
			num_of_2++;
	}

	if (num_of_e > num_of_2)
		cout << 'e' << endl;
	else if (num_of_e < num_of_2)
		cout << 2 << endl;
	else
		cout << "yee" << endl;

	return 0;
}