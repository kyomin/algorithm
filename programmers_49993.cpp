#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 스킬인지 체크 여부!
bool check[26];

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	// 스킬 체크해주기!
	for (int i = 0; i < skill.size(); i++)
	{
		check[(int)(skill[i] - 65)] = true;
	}

	int len = skill_trees.size();

	for (int num = 0; num < len; num++)
	{
		// 각 벡터의 string 원소에 대해 작업한다.
		string candidate = skill_trees[num];

		string temp = "";

		for (int i = 0; i < candidate.size(); i++)
		{
			// 만일 스킬에 포함되어 있는 문자라면
			if (check[(int)(candidate[i] - 65)])
				temp += candidate[i];
		}

		// 스킬에 부합하는 것들을 뽑아낸 후에 타당한지 판단한다.
		bool judge = false;

		for (int i = 0; i < temp.size(); i++)
		{
			// 순서가 올바르지 않은게 하나라도 있다면!
			if (temp[i] != skill[i])
			{
				judge = true;
				break;
			}
		}

		if (!judge)
		{
			answer++;
		}
	}

	return answer;
}

int main()
{
	cout << solution("CBD", {
		"BACDE", "CBADF", "AECB", "BDA"
		}) << endl;

	return 0;
}