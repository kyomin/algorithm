#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int N;
int M;
int answer = 0;
vector<int> combination;
vector<set<int>> inputs;
vector<int> response;

// DFS로 조합을 구한다
void dfs(int start, int depth) {
    // 5개를 뽑은 조합이 완성되었다면
    if (depth == 5) {
        set<int> code(combination.begin(), combination.end());

        bool flag = true;

        for (int i = 0; i < M; i++) {
            set<int> result;
            set<int> input = inputs[i];

            int ans = response[i];

            // 교집합 구하기
            set_intersection(code.begin(), code.end(),
                input.begin(), input.end(),
                inserter(result, result.begin()));

            if (result.size() == ans) {
                continue;
            }

            // 해당 시도 입력을 만족하지 않는 경우
            if (result.size() != ans) {
                flag = false;
                break;
            }
        }

        if (flag)
            answer++;

        return;
    }

    for (int i = start; i <= N; ++i) {
        combination.push_back(i);
        dfs(i + 1, depth + 1);
        combination.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    N = n;
    M = ans.size();
    response = ans;

    // 교집합을 위해 vector -> set 변환
    for (vector<int> input : q) {
        set<int> s(input.begin(), input.end());

        inputs.push_back(s);
    }

    // 조합 탐색 시작
    dfs(1, 0);

    return answer;
}