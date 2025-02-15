#include <vector>

using namespace std;

const int MAX = 1000000000;
int leftMin[1000000];
int rightMin[1000000];

int solution(vector<int> a) {
	int answer = 2;		// �� ���� �׻� ���� �� �ִ�.
	int len = a.size();
	int left_min = MAX;
	int right_min = MAX;

	// �ϳ��� ��� ó��
	if (len == 1)
		return 1;

	// �� ���� ��� ó��
	if (len == 2)
		return 2;

	// Ư�� ������ ���� �κ��� �ּڰ�
	for (int i = 0; i < len; i++) {
		if (left_min > a[i])
			left_min = a[i];

		leftMin[i] = left_min;
	}

	// Ư�� ������ ������ �κ��� �ּڰ�
	for (int i = len-1; i >= 0; i--) {
		if (right_min > a[i])
			right_min = a[i];

		rightMin[i] = right_min;
	}

	// �߰� ���ҵ鿡 ���� ó��
	for (int mid = 1; mid < len - 1; mid++) {
		// ���� �� ���纸�� �۴ٸ� ���ı��� ���� �� ����
		if (leftMin[mid] < a[mid] && rightMin[mid] < a[mid])
			continue;

		answer++;
	}

	return answer;
}