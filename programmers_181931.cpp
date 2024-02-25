#include <string>
#include <vector>
using namespace std;

/*
	@param a				ù°��
	@param d				����
	@param included				boolean �迭

	@return				included�� true�� �׵��� i + 1�׵鸸 ���� ��
*/
int solution(int a, int d, vector<bool> included) {
	int answer = 0;
	int len = included.size();

	for (int i = 0; i < len; i++) {
		if (included[i])
			answer += a;

		a += d;
	}

	return answer;
}