#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// �� �Լ�
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

		// �ش� Ű�� �� ã�Ҵٸ�
		if (m.find(str) == m.end())
		{
			m[str] = 1;
		}
		// �ش� Ű�� ã�Ҵٸ�
		else
		{
			// �� ����!
			m.find(str)->second += 1;
		}
	}

	// map ���� m�� ���� �� ����� ���̴�.
	// �̸� pair�� �̿��Ͽ� ���Ϳ� ����.

	// algorithm�� ���ǵ� ī�� �Լ�. �� ��° ���ڴ� ����� ���� �����̳�!
	copy(m.begin(), m.end(), back_inserter(v));

	sort(v.begin(), v.end(), com);

	cout << v[0].first << endl;

	return 0;
}