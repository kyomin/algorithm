#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct info {
	int id;			// ȸ�� id
	int weight;		// ��ǰ ����
	int checkStand;	// ���� ����
}Info;

bool comp(const Info &i1, const Info &i2) {
	if (i1.weight < i2.weight) {
		return true;
	}
	else if (i1.weight == i2.weight) {
		if (i1.checkStand > i2.checkStand)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	int N, k;
	// ��� id���� ���� ����
	vector<int> result;

	// �� ������
	vector<Info> customers;

	// ����
	vector<Info> checkStand;

	// ����ִ� ����
	vector<int> emptyCheckStand;

	// ���� ��� ���� ���� ����Ų��.
	int curPos = 0;

	cin >> N >> k;

	for (int i = 0; i < N; i++) {
		Info info;

		cin >> info.id;
		cin >> info.weight;

		customers.push_back(info);
	}

	// �ϴ� �ʱ� ���� �� �о�ֱ�
	for (int i = 1; i <= k; i++) {
		customers[curPos].checkStand = i;
		checkStand.push_back(customers[curPos]);
		curPos++;
	}

	while (curPos < N) {
		// ����ִ� ���밡 ���ٸ�
		if (emptyCheckStand.size() == 0) {
			// ���ش�� �������ְ�
			sort(checkStand.begin(), checkStand.end(), comp);

			// �� �� ����� weight�� ���� �ּ� weight�̴�.
			int minWeight = checkStand[0].weight;

			for (int i = 0; i < checkStand.size(); i++) {
				if (checkStand[i].weight == minWeight) {
					// ���� ���������� �ϴ� �ּ� ���Զ�� ����ִٰ� ǥ���Ѵ�.
					emptyCheckStand.push_back(checkStand[i].checkStand);
					
					checkStand[i].weight -= minWeight;

					// �׸��� ��� id�� ������� �߰�!
					result.push_back(checkStand[i].id);
				}
				else {
					checkStand[i].weight -= minWeight;
				}
			}
		}
		else {		// ����ִ� ���밡 �ִٸ�
			sort(emptyCheckStand.begin(), emptyCheckStand.end());

			for (int i = 0; i < emptyCheckStand.size(); i++) {
				if (curPos >= N)
					break;
				
				// ���� �� ���� ���� �־��ְ�
				customers[curPos].checkStand = emptyCheckStand[i];
				
				// ���� ����� �о�ְ�(�ε��� �����ֱ� ����)
				checkStand[i] = customers[curPos];

				// ���� ������ ������ �̵�!
				curPos++;
			}

			emptyCheckStand.clear();
		}
	}

	/* ���� ���� �� ���뿡 ������ ���� ���뿡 �����ִ� ���� �ڵ鸵! */
	
	// ���ش�� �������ְ�
	sort(checkStand.begin(), checkStand.end(), comp);

	for (int i = 0; i < checkStand.size(); i++) {
		if(checkStand[i].weight != 0)
			result.push_back(checkStand[i].id);
	}

	unsigned long long ans = 0;

	for (int i = 0; i < result.size(); i++) {
		ans += result[i] * (i + 1);
	}

	cout << ans << '\n';
	
	return 0;
}