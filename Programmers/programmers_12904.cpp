#include <string>
#include <algorithm>

using namespace std;

const int MAX = 2501;		// ���ڿ� �ִ� ����

bool cache[MAX][MAX];		// �޸����̼��� ���� �迭
char arr[MAX];

int solution(string s) {
	int answer = 0;
	int len = s.size();

	for (int i = 0; i < len; i++)
		arr[i + 1] = s[i];

	// ���� 1�� ���� ó��
	for (int i = 1; i <= len; i++)
		cache[i][i] = true;

	// ���� 2�� ���� ó��
	for (int i = 1; i < len; i++)
		if (arr[i] == arr[i + 1])
			cache[i][i + 1] = true;

	// ���� 3 �̻� ���� ó��
	for (int i = 2; i < len; i++)
		for (int j = 1; j <= len - i; j++)
			// �� �ڰ� ����, �� ��� ������ �Ӹ������ ���
			if (arr[j] == arr[j + i] && cache[j + 1][j + i - 1])
				cache[j][j + i] = true;

	for (int i = 1; i <= len; i++)
		for (int j = i; j <= len; j++)
			if(cache[i][j])
				answer = max(answer, (j-i+1));

	return answer;
}