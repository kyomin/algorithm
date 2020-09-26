#include <string>
#include <vector>
#include <iostream>

using namespace std;

// ��ų���� üũ ����!
bool check[26];

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	// ��ų üũ���ֱ�!
	for (int i = 0; i < skill.size(); i++)
	{
		check[(int)(skill[i] - 65)] = true;
	}

	int len = skill_trees.size();

	for (int num = 0; num < len; num++)
	{
		// �� ������ string ���ҿ� ���� �۾��Ѵ�.
		string candidate = skill_trees[num];

		string temp = "";

		for (int i = 0; i < candidate.size(); i++)
		{
			// ���� ��ų�� ���ԵǾ� �ִ� ���ڶ��
			if (check[(int)(candidate[i] - 65)])
				temp += candidate[i];
		}

		// ��ų�� �����ϴ� �͵��� �̾Ƴ� �Ŀ� Ÿ������ �Ǵ��Ѵ�.
		bool judge = false;

		for (int i = 0; i < temp.size(); i++)
		{
			// ������ �ùٸ��� ������ �ϳ��� �ִٸ�!
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