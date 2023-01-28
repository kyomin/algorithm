#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int index;	// ���� �÷��� ���� ���� ����

bool comp(const vector<int>& v1, const vector<int>& v2) {
	// ���� �����ϸ� ù ��° �÷��� ���� �������� ��������
	if (v1[index] == v2[index]) {
		return v1[0] > v2[0] ? true : false;
	}
	else {
		return v1[index] < v2[index] ? true : false;
	}
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	int answer = 0;
	index = col - 1;

	sort(data.begin(), data.end(), comp);

	for (int i = row_begin; i <= row_end; i++) {
		vector<int> row = data[i - 1];
		int sum = 0;

		for (int n : row)
			sum += (n%i);

		answer ^= sum;
	}

	return answer;
}