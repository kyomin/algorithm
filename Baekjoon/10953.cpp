#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SPLIT(vector<string>& v, string str, char token) {
	int start = 0;
	int len = str.size();

	for (int i = 0; i < len; i++) {
		// ���� ���ڿ��� ó������ ��ū ���ڸ� ������ �ƹ��͵� ���� �ʴ´�. 
		if (i == 0 && str[i] == token) {
			start = i + 1;
			continue;
		}

		// ���ڿ��� ���̶��
		if (i == len - 1)
			v.push_back(str.substr(start, i + 1));
		else if (str[i] == token) {
			v.push_back(str.substr(start, i - start));
			start = i + 1;
		}
	}
}

int main() {
	int N;
	cin >> N;

	vector<string> v;
	vector<int> result;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		SPLIT(v, str, ',');

		int sum = (int)(v[0][0] - '0') + (int)(v[1][0] - '0');

		result.push_back(sum);

		v.clear();
	}

	for (int i = 0; i < N; i++)
		cout << result[i] << '\n';

	return 0;
}