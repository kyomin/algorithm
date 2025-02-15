#include <string>

using namespace std;

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		int ans = 0;
		int stones_len = stones.length();
		int jewels_len = jewels.length();

		for (int i = 0; i < stones_len; i++) {
			char stone = stones[i];

			for (int j = 0; j < jewels_len; j++) {
				if (stone == jewels[j]) {
					ans++;
					break;
				}
			}
		}

		return ans;
	}
};