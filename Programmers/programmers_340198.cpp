#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool canSpread(int mat, vector<vector<string>> park) {
    int R = park.size() - mat;
    int C = park[0].size() - mat;

    for (int currentR = 0; currentR <= R; currentR++) {
        for (int currentC = 0; currentC <= C; currentC++) {
            bool flag = true;

            for (int r = currentR; r < currentR + mat; r++) {
                if (!flag) {
                    break;
                }

                for (int c = currentC; c < currentC + mat; c++) {
                    if (park[r][c] != "-1") {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                return true;
            }
        }
    }

    return false;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;

    sort(mats.begin(), mats.end());

    for (int i = mats.size() - 1; i >= 0; i--) {
        int mat = mats[i];

        if (canSpread(mat, park)) {
            answer = mat;
            break;
        }
    }

    return answer;
}