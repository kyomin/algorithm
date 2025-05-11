#include <iostream>
#include <string>
using namespace std;

int main() {
	const string DKSH = "DKSH";

	int count = 0;
	string str;
	cin >> str;

	int lastIndex = str.length() - DKSH.length();

	for (int i = 0; i <= lastIndex; i++) 
		if (str.substr(i, 4) == DKSH)
			count++;
	
	cout << count << endl;

	return 0;
}