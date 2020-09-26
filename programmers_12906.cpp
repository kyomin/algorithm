#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	int len = arr.size();

	// �ϴ� ù ��° ���Ҵ� ����ֱ�!
	answer.push_back(arr[0]);

	for (int i = 1; i < len; i++) {
		// ���� �����ϰ� ���ӵ��� ���� ���� ����ֱ�!
		if (arr[i] != arr[i - 1])
			answer.push_back(arr[i]);
	}

	return answer;
}

int main() {
	vector<int> v;

	// Test 1
	v = solution({1,1,3,3,0,1,1});

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	cout << endl;

	// Test 2
	v = solution({ 4,4,4,3,3 });

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	cout << endl;

	return 0;
}