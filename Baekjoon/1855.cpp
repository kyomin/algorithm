#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int col;
	string encrypted_str;
	cin >> col >> encrypted_str;

	int len = encrypted_str.length();
	int row = len / col;

	vector<string> a;
	
	for (int i = 0; i < row; i++) {
		string str = "";
		
		for (int j = 0; j < col; j++) {
			int index = (i*col) + j;
			str += encrypted_str[index];
		}

		if (i % 2 == 1)
			reverse(str.begin(), str.end());

		a.push_back(str);
	}

	string plain_str = "";
	
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			plain_str += a[j][i];

	cout << plain_str << '\n';
	
	return 0;
}