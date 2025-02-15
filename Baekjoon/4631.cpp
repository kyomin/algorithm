#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int count = 1;

	while (true) {
		int N;
		cin >> N;

		if (N == 0)
			break;

		vector<string> v;

		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}

		string *result = new string[N];

		int num = N / 2;

		for (int i = 0; i < num; i++) {
			result[i] = v[i * 2];
			result[N - i - 1] = v[i * 2 + 1];
		}

		if (N % 2 == 1)
			result[num] = v[N - 1];

		cout << "SET " << count << endl;

		for (int i = 0; i < N; i++)
			cout << result[i] << '\n';

		count++;
	}

	return 0;
}