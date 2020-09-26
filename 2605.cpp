#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	vector<int> line;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		// ù ��° �л��̶��
		if (i == 0) {
			line.push_back(i + 1);
			continue;
		}

		vector<int> copy;

		// ���� �л��� �̵��� ���� �ε���
		num = i - num;

		for (int j = 0; j < num; j++)
			copy.push_back(line[j]);

		copy.push_back(i + 1);

		for (int j = num; j < line.size(); j++)
			copy.push_back(line[j]);

		line = copy;
	}

	for (int i = 0; i < line.size(); i++)
		cout << line[i] << ' ';

	cout << '\n';

	return 0;
}