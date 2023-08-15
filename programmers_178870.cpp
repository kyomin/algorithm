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
			if (end - start + 1 < subLen) {	// ���̰� �� ª�� ������ ���
				subLen = end - start + 1;
				result = { start, end };	// ����
			}
			else if (end - start + 1 == subLen) {
				// ���� �ε����� �� ���� ���
				if (start < result.first)
					result = { start, end };	// ����
			}

			sum -= sequence[start++];
		}
		else {
			sum -= sequence[start++];
		}
	}

	return { result.first, result.second };
}