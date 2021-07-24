#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int makeRank(int num) {
	int ret;

	switch (num) {
	case 6:
		ret = 1;
		break;
	case 5:
		ret = 2;
		break;
	case 4:
		ret = 3;
		break;
	case 3:
		ret = 4;
		break;
	case 2:
		ret = 5;
		break;
	default:
		ret = 6;
		break;
	}

	return ret;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	const int len = 6;
	vector<int> answer;
	int num_of_matches = 0;
	int num_of_zero = 0;
	
	// 계산의 편의를 위해 정렬
	sort(lottos.begin(), lottos.end());
	sort(win_nums.begin(), win_nums.end());

	for (int i = 0; i < len; i++) {
		int lotto_num = lottos[i];

		if (lotto_num == 0) {
			num_of_zero += 1;
			continue;
		}

		for (int j = 0; j < len; j++) {
			int win_num = win_nums[j];

			if (lotto_num == win_num)
				num_of_matches += 1;
		}
	}

	answer.push_back(makeRank(num_of_matches + num_of_zero));
	answer.push_back(makeRank(num_of_matches));

	return answer;
}