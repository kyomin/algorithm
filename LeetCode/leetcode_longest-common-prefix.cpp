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

			// ù ��° ���ڿ��� ������� �۾��� �����Ѵ�.
			if (strs[0].size() <= idx)
				return lcp;

			ch = strs[0][idx];

			for (int i = 1; i < len; i++) {
				// ù ��° ���ڿ��� ���������� �ε����� ���ڿ� ���̸� �Ѵ��� üũ�Ѵ�.
				if (strs[i].size() <= idx)
					return lcp;

				if (strs[i][idx] != ch)
					return lcp;
			}

			// ������� �Դٴ°� ������ ���� �ʰ�, Ư�� �ε����� ���ڰ� ��� ������ �ǹ��Ѵ�.
			idx++;
			lcp += ch;
		}
	}
};