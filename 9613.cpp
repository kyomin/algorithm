#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;

	}

	return a;
}

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
			v.push_back(str.substr(start, i));
			start = i + 1;
		}
	}
}

int main() {
	int t;
	cin >> t;

	cin.ignore();

	for (int i = 0; i < t; i++) {
		vector<string> vec;
		vector<int> int_vector;
		string str;

		// ������� �����Ͽ� string ������ �Է�!
		getline(cin, str);
		SPLIT(vec, str, ' ');

		int start = 1;
		int iter = 2;
		unsigned long sum = 0;
		int len = vec.size();

		// ������ �� ��ҿ� ���� string -> int ��ȯ �۾�!
		for (int i = 0; i < len; i++)
			int_vector.push_back(atoi(vec[i].c_str()));

		while (start != len - 1) {
			for (int i = iter; i < len; i++)
				sum += GCD(int_vector[start], int_vector[i]);

			iter += 1;
			start += 1;
		}

		cout << sum << endl;
	}

	return 0;
}