#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	int start = 0;
	int end = 0;
	int sum = sequence[0];
	int subLen = sequence.size() + 1;
	pair<int, int> result;

	while (start <= end && end < sequence.size()) {
		if (sum < k) {
			sum += sequence[++end];
		}
		else if (sum == k) {
			if (end - start + 1 < subLen) {	// 길이가 더 짧은 수열인 경우
				subLen = end - start + 1;
				result = { start, end };	// 갱신
			}
			else if (end - start + 1 == subLen) {
				// 시작 인덱스가 더 작은 경우
				if (start < result.first)
					result = { start, end };	// 갱신
			}

			sum -= sequence[start++];
		}
		else {
			sum -= sequence[start++];
		}
	}

	return { result.first, result.second };
}