#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100][100];

void init() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			arr[i][j] = 0;
}

int main() {
	for (int t = 1; t <= 10; t++) {
		vector<int> v;
		int T;
		cin >> T;
		init();

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> arr[i][j];

		// �� ���� �� ���ϱ�
		for (int r = 0; r < 100; r++) {
			int sum = 0;

			for (int c = 0; c < 100; c++)
				sum += arr[r][c];

			v.push_back(sum);
		}

		// �� ���� �� ���ϱ�
		for (int c = 0; c < 100; c++) {
			int sum = 0;

			for (int r = 0; r < 100; r++)
				sum += arr[r][c];

			v.push_back(sum);
		}

		// ������ �밢�� �Ʒ� �� ���ϱ�
		int sum = 0;
		for (int i = 0; i < 100; i++)
			sum += arr[i][i];

		v.push_back(sum);

		// ���� �밢�� �Ʒ� �� ���ϱ�
		sum = 0;
		for (int i = 0; i < 100; i++)
			sum += arr[i][100 - 1 - i];
		
		v.push_back(sum);

		cout << '#' << t << ' ' << *max_element(v.begin(), v.end()) << '\n';
	}

	return 0;
}