#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> students;
	int ans;
	int N, K;
	cin >> N >> K;
	students.resize(N);

	for (int i = 0; i < N; i++)
		cin >> students[i];

	sort(students.begin(), students.end());

	// ��踦 ������ ���� ����� ���
	ans = students[N - 1] - students[0];

	// ���� i�� i-1 ���̿� ��踦 �߰��Ѵٸ� students[i]-students[i-1] ��ŭ�� ��뿡�� ���ܵȴ�.
	// �ᱹ K���� ���� ������ ��, ���� ����� ���� �Ϸ���
	// K-1�� ��� �� ���� ����� ū ��踦 ���� �ȴ�.
	// ��, students[i]-students[i-1]�� ���� �迭�� ������ ��, �����Ͽ� K-1���� ū ����� ���ؼ�
	// ��ü ��뿡�� ���ָ� �ȴ�.
	for (int i = N - 1; i >= 1; i--)
		students[i] = students[i] - students[i - 1];
	students[0] = 0;
	sort(students.begin(), students.end());

	for (int i = N - 1; K > 1; K--, i--)
		ans -= students[i];

	cout << ans << endl;

	return 0;
}