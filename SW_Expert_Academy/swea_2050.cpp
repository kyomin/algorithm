#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> ans;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
		ans.push_back(to_string((int)(str[i] - 'A') + 1));

	for (int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << ' ';

	cout << ans[ans.size() - 1] << '\n';

	return 0;
}