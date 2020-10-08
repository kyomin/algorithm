#include <string>
#include <algorithm>

using namespace std;

const int MAX = 2501;		// 문자열 최대 길이

bool cache[MAX][MAX];		// 메모제이션을 위한 배열
char arr[MAX];

int solution(string s) {
	int answer = 0;
	int len = s.size();

	for (int i = 0; i < len; i++)
		arr[i + 1] = s[i];

	// 길이 1에 대한 처리
	for (int i = 1; i <= len; i++)
		cache[i][i] = true;

	// 길이 2에 대한 처리
	for (int i = 1; i < len; i++)
		if (arr[i] == arr[i + 1])
			cache[i][i + 1] = true;

	// 길이 3 이상에 대한 처리
	for (int i = 2; i < len; i++)
		for (int j = 1; j <= len - i; j++)
			// 앞 뒤가 같고, 그 가운데 수들이 팰린드롬인 경우
			if (arr[j] == arr[j + i] && cache[j + 1][j + i - 1])
				cache[j][j + i] = true;

	for (int i = 1; i <= len; i++)
		for (int j = i; j <= len; j++)
			if(cache[i][j])
				answer = max(answer, (j-i+1));

	return answer;
}