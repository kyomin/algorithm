#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int len = strs.size();
		string lcp = "";
		int idx = 0;

		if (len < 1) 
			return lcp;
		
		while (true) {
			char ch;

			// 첫 번째 문자열을 대상으로 작업을 진행한다.
			if (strs[0].size() <= idx)
				return lcp;

			ch = strs[0][idx];

			for (int i = 1; i < len; i++) {
				// 첫 번째 문자열과 마찬가지로 인덱스가 문자열 길이를 넘는지 체크한다.
				if (strs[i].size() <= idx)
					return lcp;

				if (strs[i][idx] != ch)
					return lcp;
			}

			// 여기까지 왔다는건 범위를 넘지 않고, 특정 인덱스의 문자가 모두 같음을 의미한다.
			idx++;
			lcp += ch;
		}
	}
};