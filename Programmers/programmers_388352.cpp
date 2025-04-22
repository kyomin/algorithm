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

// DFS�� ������ ���Ѵ�
void dfs(int start, int depth) {
    // 5���� ���� ������ �ϼ��Ǿ��ٸ�
    if (depth == 5) {
        set<int> code(combination.begin(), combination.end());

        bool flag = true;

        for (int i = 0; i < M; i++) {
            set<int> result;
            set<int> input = inputs[i];

            int ans = response[i];

            // ������ ���ϱ�
            set_intersection(code.begin(), code.end(),
                input.begin(), input.end(),
                inserter(result, result.begin()));

            if (result.size() == ans) {
                continue;
            }

            // �ش� �õ� �Է��� �������� �ʴ� ���
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

    // �������� ���� vector -> set ��ȯ
    for (vector<int> input : q) {
        set<int> s(input.begin(), input.end());

        inputs.push_back(s);
    }

    // ���� Ž�� ����
    dfs(1, 0);

    return answer;
}