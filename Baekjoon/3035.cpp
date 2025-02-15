#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> map;
	vector<string> result;
	int R, C, ZR, ZC;
	cin >> R >> C >> ZR >> ZC;

	for (int r = 0; r < R; r++) {
		string s;
		cin >> s;

		map.push_back(s);
	}

	for (int r = 0; r < R; r++) {
		string s = map[r];
		string temp = "";

		for (int c = 0; c < C; c++) {
			char ch = s[c];

			for (int zc = 0; zc < ZC; zc++)
				temp += ch;
		}

		for (int zr = 0; zr < ZR; zr++)
			result.push_back(temp);
	}

	int len = result.size();

	for (int i = 0; i < len; i++) 
		cout << result[i] << endl;

	return 0;
}