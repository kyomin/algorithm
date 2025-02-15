#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;
	
	int R = wallpaper.size();
	int C = wallpaper[0].length();

	int endLeft = C;
	int endRight = 0;
	int endTop = R;
	int endBottom = 0;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (wallpaper[r][c] == '#') {
				if (endLeft > c)
					endLeft = c;

				if (endRight < c)
					endRight = c;

				if (endTop > r)
					endTop = r;

				if (endBottom < r)
					endBottom = r;
			}
		}
	}

	endRight += 1;
	endBottom += 1;

	answer.push_back(endTop);
	answer.push_back(endLeft);
	answer.push_back(endBottom);
	answer.push_back(endRight);

	return answer;
}