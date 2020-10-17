#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;

		int cnt = 0;

		while (str != "6174") {
			// �������� ���� -> ���� �� �ִ� ���� ���� ���ڰ� �ȴ�
			sort(str.begin(), str.end());

			string low = str;

			// �������� ���� �� �������� ���� �� �ִ� ���� ū ���� �ȴ�.
			reverse(str.begin(), str.end());

			int result = atoi(str.c_str()) - atoi(low.c_str());

			str = to_string(result);

			if (str.size() < 4) {
				string temp = "";
				int zero_cnt = 4 - str.size();
				
				for (int i = 0; i < zero_cnt; i++)
					temp += "0";

				str = (temp + str);
			}

			cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}