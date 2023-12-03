#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
	int answer = health;
	int continuous = 0;	// ���� ����
	int castingTime = bandage[0];	// ���� �ð�
	int recoveryPerSecond = bandage[1];	// �ʴ� ȸ����
	int extraRecovery = bandage[2];	// �߰� ȸ����
	int lastTime = 0;	// ������ ������ ���� �ð�
	int last = attacks.size();
	map<int, int> attackTimeAndDamage;

	for (int i = 0; i < last; i++) {
		int attackTime = attacks[i][0];
		int damage = attacks[i][1];

		attackTimeAndDamage[attackTime] = damage;

		if (i == last - 1)
			lastTime = attackTime;
	}

	for (int t = 1; t <= lastTime; t++) {
		int damage = attackTimeAndDamage.find(t) != attackTimeAndDamage.end() ? attackTimeAndDamage[t] : 0;

		if (damage) {
			answer -= damage;
			continuous = 0;	// ���� ���� �ʱ�ȭ
		}
		else {
			answer += recoveryPerSecond;
			continuous += 1;
		}

		// ���� �ð����� �������� ���� ���
		if (continuous == castingTime) {
			answer += extraRecovery;
			continuous = 0;
		}

		// �ִ� ü���� �ѱ� ���
		if (answer >= health)
			answer = health;

		// ü���� 0 ���ϰ� �� ���
		if (answer <= 0) {
			answer = -1;
			break;
		}
	}

	return answer;
}