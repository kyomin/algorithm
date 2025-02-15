#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int R, C;
	int outside;

	for (int c = 1; c <= yellow; c++) {
		if (yellow % c == 0) {
			R = (yellow / c);
			C = c;
			outside = (2 * R) + (2 * (C + 2));

			if (outside == brown)
				break;
		}
	}

	answer = { R + 2, C + 2 };

	return answer;
}