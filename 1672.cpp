#include <iostream>
#include <string>
#include <map>

using namespace std;

char table[4][4] = {
	{'A', 'C', 'A', 'G'},
	{'C', 'G', 'T', 'A'},
	{'A', 'T', 'C', 'G'},
	{'G', 'A', 'G', 'T'}
};

int main() {
	map<char, int> m;
	m['A'] = 0;
	m['G'] = 1;
	m['C'] = 2;
	m['T'] = 3;

	int N;
	string str;
	cin >> N >> str;

	while (str.size() > 1) {
		int len = str.size();
		int row = m.find(str[len - 2])->second;
		int col = m.find(str[len - 1])->second;

		string tmp = str.substr(0, len - 2);
		tmp += table[row][col];

		str = tmp;
	}

	cout << str << '\n';

	return 0;
}