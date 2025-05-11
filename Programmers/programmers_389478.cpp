#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    vector<vector<int>> matrix;
    vector<int> row;
    int rowIndex = 0;

    for (int i = 1; i <= n; ++i) {
        row.push_back(i);

        if (row.size() == w) {
            if (rowIndex % 2 == 1) {
                reverse(row.begin(), row.end());
            }

            matrix.push_back(row);
            row.clear();
            rowIndex++;
        }
    }

    if (!row.empty()) {
        while (row.size() < w) {
            row.push_back(0);
        }

        if (rowIndex % 2 == 1) {
            reverse(row.begin(), row.end());
        }

        matrix.push_back(row);
    }

    int targetR = 0;
    int targetC = 0;
    int R = matrix.size();
    int C = w;

    for (int r = 0; r < R; r++) {
        bool found = false;

        for (int c = 0; c < C; c++) {
            if (matrix[r][c] == num) {
                found = true;
                targetR = r;
                targetC = c;

                break;
            }
        }

        if (found)
            break;
    }

    for (int r = targetR; r < R; r++) {
        if (matrix[r][targetC] != 0) 
            answer++;        
    }

    return answer;
}