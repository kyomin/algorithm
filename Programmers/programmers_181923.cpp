#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	@param arr		정수 배열
	@param queries		[s, e, k] 꼴의 배열을 원소로 갖는 배열

	@return			각 query마다 순서대로 s ≤ i ≤ e인 모든 i에 대해 k보다 크면서 가장 작은 arr[i]를 찾은 배열
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