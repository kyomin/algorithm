#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> result;
	int N;
	cin >> N;

	for (int n = 1; n <= N; n++) {
		string num = to_string(n);
		int len = num.size();
		int cnt = 0;

		for (int i = 0; i < len; i++)
			if (num[i] == '3' || num[i] == '6' || num[i] == '9')
				cnt++;

		if (cnt == 0) {
			result.push_back(num);
			continue;
		}

		string temp = "";

		for (int i = 0; i < cnt; i++)
			temp += "-";

		result.push_back(temp);
	}

	for (int i = 0; i < result.size() - 1; i++)
		cout << result[i] << ' ';

	cout << result[result.size() - 1] << '\n';

	return 0;
}