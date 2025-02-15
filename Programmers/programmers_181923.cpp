#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	@param arr		���� �迭
	@param queries		[s, e, k] ���� �迭�� ���ҷ� ���� �迭

	@return			�� query���� ������� s �� i �� e�� ��� i�� ���� k���� ũ�鼭 ���� ���� arr[i]�� ã�� �迭
*/
vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
	vector<int> answer;

	for (vector<int> query : queries) {
		int s = query[0];
		int e = query[1];
		int k = query[2];
		int m = -1;

		for (int i = s; i <= e; i++) {
			int n = arr[i];

			if (n > k) {
				if (m == -1) {
					m = n;
				}
				else {
					m = min(m, n);
				}
			}
		}

		answer.push_back(m);
	}

	return answer;
}