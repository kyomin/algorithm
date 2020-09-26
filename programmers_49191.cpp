#include <string>
#include <vector>

using namespace std;

int map[101][101];

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	int len = results.size();

	for (int i = 0; i < len; i++) 
		map[results[i][0]][results[i][1]] = 1;	// A > B를 만족한다.
	
	// 플로이드 와샬 알고리즘 적용
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][k] && map[k][j])
					map[i][j] = 1;

	for (int i = 1; i <= n; i++) {
		int cnt = 0;

		for (int j = 1; j <= n; j++) 
			if (!map[i][j] && !map[j][i])
				cnt++;
		
		if (cnt - 1 == 0)
			answer++;
	}

	return answer;
}