#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;

	int len = arr.size();

	// �ϴ� ù ��° ���Ҵ� ����ֱ�!
	answer.push_back(arr[0]);

	for (int i = 1; i < len; i++)
		// ���� �����ϰ� ���ӵ��� ���� ���� ����ֱ�!
		if (arr[i] != arr[i - 1])
			answer.push_back(arr[i]);

	return answer;
}