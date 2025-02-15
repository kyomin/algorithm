#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int val_index;	// ext�� ���� �ε���
int sort_index;	// sort_by�� ���� �ε���

/*
	sort_by�� �ش��ϴ� ���� �������� �������� ����
*/
bool comp(const vector<int> &data1, const vector<int> &data2) {
	if (data1[sort_index] < data2[sort_index])
		return true;
	else
		return false;
}

/*
	@param data		1���� ������ [�ڵ� ��ȣ(code), ������(date), �ִ� ����(maximum), ���� ����(remain)]���� ������ 2���� ����
	@param ext		"code", "date", "maximum", "remain" �� �ϳ��� ���ڿ�
	@param val_ext	ext�� �ش��ϴ� ���ذ�
	@param sort_by	"code", "date", "maximum", "remain" �� �ϳ��� ���ڿ�

	@return			data���� ext ���� val_ext���� ���� �����͸� ���� ��, sort_by�� �ش��ϴ� ���� �������� �������� ������ ����
*/
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
	vector<vector<int>> answer;

	if (ext == "code")
		val_index = 0;
	else if (ext == "date")
		val_index = 1;
	else if (ext == "maximum")
		val_index = 2;
	else
		val_index = 3;

	// �켱 data���� ext ���� val_ext���� ���� �����͸� ��󳽴�.
	for (vector<int> d : data) {
		int val = d[val_index];

		if (val < val_ext)
			answer.push_back(d);
	}

	if (sort_by == "code")
		sort_index = 0;
	else if (sort_by == "date")
		sort_index = 1;
	else if (sort_by == "maximum")
		sort_index = 2;
	else
		sort_index = 3;

	sort(answer.begin(), answer.end(), comp);

	return answer;
}