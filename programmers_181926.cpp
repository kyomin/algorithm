#include <string>
#include <vector>
using namespace std;

/*
	@param n		control�� ���� �ٲ�� ����
	@param control		"w", "a", "s", "d"�� 4���� ����

	@return			��Ģ�� ���� n�� �ٲ��� �� ���� �������� ������ n�� ��
*/
int solution(int n, string control) {
	int answer = n;
	int len = control.length();

	for (int i = 0; i < len; i++) {
		char ch = control[i];

		switch (ch) {
			case 'w': {
				answer += 1;
				break;
			}
			case 's': {
				answer -= 1;
				break;
			}
			case 'd': {
				answer += 10;
				break;
			}
			default: {
				answer -= 10;
			}
		}
	}

	return answer;
}