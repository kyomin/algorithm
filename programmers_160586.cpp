#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;

	for (int i = 0; i < targets.size(); i++) {
		string target = targets[i];
		int sum = 0;

		for (int j = 0; j < target.length(); j++) {
			char targetChar = target[j];
			int cnt = -1;

			for (int k = 0; k < keymap.size(); k++) {
				string key = keymap[k];

				for (int l = 0; l < key.length(); l++) {
					if (key[l] == targetChar) {
						int n = l + 1;

						if (cnt == -1 || n < cnt) {
							cnt = n;
							break;
						}
					}
				}
			}

			if (cnt != -1) {
				sum += cnt;
			}
			else {
				sum = -1;
				break;
			}
		}

		answer.push_back(sum);
	}

	return answer;
}