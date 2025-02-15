#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string result = "";
	vector<string> v;
	int max = 0;

	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;

		if (str.size() > max)
			max = str.size();

		v.push_back(str);
	}

	for (int i = 0; i < max; i++)
		for (int j = 0; j < 5; j++)
			if (v[j].size() - 1 >= i)
				result += v[j][i];

	cout << result << endl;

	return 0;
}