#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 비교 함수
bool com(const pair<string, int> &p1, const pair<string, int> &p2)
{
	if (p1.second > p2.second)
	{
		return true;
	}
	else if (p1.second == p2.second)
	{
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

int main() {
	map<string, int> m;
	vector<pair<string, int>> v;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		// 해당 키를 못 찾았다면
		if (m.find(str) == m.end())
		{
			m[str] = 1;
		}
		// 해당 키를 찾았다면
		else
		{
			// 빈도 증가!
			m.find(str)->second += 1;
		}
	}

	// map 변수 m에 값이 다 담겼을 것이다.
	// 이를 pair를 이용하여 벡터에 담자.

	// algorithm에 정의된 카피 함수. 세 번째 인자는 결과를 담을 컨테이너!
	copy(m.begin(), m.end(), back_inserter(v));

	sort(v.begin(), v.end(), com);

	cout << v[0].first << endl;

	return 0;
}