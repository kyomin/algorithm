#include <string>
#include <vector>
using namespace std;

int solution(int n, int m, vector<int> section) {
	int answer = 0;
	vector<bool> wall(n, true);

	for (int i = 0; i < section.size(); i++) {
		int num = section[i];
		wall[num - 1] = false;
	}

	for (int i = 0; i < n; i++) {
		if (!wall[i]) {
			answer++;

			for (int j = i; j < (i + m); j++) {
				if (j >= n)
					break;

				wall[j] = true;
			}
		}
	}

	return answer;
}