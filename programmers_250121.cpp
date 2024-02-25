#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int val_index;	// ext에 따른 인덱스
int sort_index;	// sort_by에 따른 인덱스

/*
	sort_by에 해당하는 값을 기준으로 오름차순 정렬
*/
bool comp(const vector<int> &data1, const vector<int> &data2) {
	if (data1[sort_index] < data2[sort_index])
		return true;
	else
		return false;
}

/*
	@param data		1차원 벡터인 [코드 번호(code), 제조일(date), 최대 수량(maximum), 현재 수량(remain)]으로 구성된 2차원 벡터
	@param ext		"code", "date", "maximum", "remain" 중 하나의 문자열
	@param val_ext	ext에 해당하는 기준값
	@param sort_by	"code", "date", "maximum", "remain" 중 하나의 문자열

	@return			data에서 ext 값이 val_ext보다 작은 데이터만 뽑은 후, sort_by에 해당하는 값을 기준으로 오름차순 정렬한 벡터
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

	// 우선 data에서 ext 값이 val_ext보다 작은 데이터를 골라낸다.
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