#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	
	sort(times.begin(), times.end());

	long long left = 0;								// �ּ� �ð� 1��
	long long right = times[times.size() - 1];	// �ִ� �ð�
	right *= n;
	answer = right;		// �ϴ� ������ �ִ� �ɸ��� �ð����� ����(�־�)
	long long mid;

	// ���� �����Ͱ� �������� �������� ���� ������ => �̺�Ž�� ����
	while (left <= right) {
		long long done = 0;		// �ش� mid���� �� �˻�뿡�� �˻��� �� �ִ� �� ��� ���� ��´�
		mid = (left + right) / 2;

		for (auto time : times)
			done += (mid / time);

		// �˻��ؾ� �ϴ� ����� ������ ���� ���
		if (done < n)
			left = mid + 1;
		// �˻��ؾ� �ϴ� ����� ������ ���� ���
		else {
			if (mid <= answer) answer = mid;
			right = mid - 1;
		}
	}

	return answer;
}