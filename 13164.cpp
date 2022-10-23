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

	// 경계를 나누지 않을 경우의 비용
	ans = students[N - 1] - students[0];

	// 만약 i와 i-1 사이에 경계를 추가한다면 students[i]-students[i-1] 만큼은 비용에서 제외된다.
	// 결국 K개의 조로 나눴을 때, 가장 비용을 적게 하려면
	// K-1의 경계 중 가장 비용이 큰 경계를 고르면 된다.
	// 즉, students[i]-students[i-1]의 값을 배열에 저장한 뒤, 정렬하여 K-1개의 큰 비용을 구해서
	// 전체 비용에서 빼주면 된다.
	for (int i = N - 1; i >= 1; i--)
		students[i] = students[i] - students[i - 1];
	students[0] = 0;
	sort(students.begin(), students.end());

	for (int i = N - 1; K > 1; K--, i--)
		ans -= students[i];

	cout << ans << endl;

	return 0;
}