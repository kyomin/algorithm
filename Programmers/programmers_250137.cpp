#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
	int answer = health;
	int continuous = 0;	// 연속 성공
	int castingTime = bandage[0];	// 시전 시간
	int recoveryPerSecond = bandage[1];	// 초당 회복량
	int extraRecovery = bandage[2];	// 추가 회복량
	int lastTime = 0;	// 몬스터의 마지막 공격 시간
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
			continuous = 0;	// 연속 성공 초기화
		}
		else {
			answer += recoveryPerSecond;
			continuous += 1;
		}

		// 시전 시간까지 연속으로 감은 경우
		if (continuous == castingTime) {
			answer += extraRecovery;
			continuous = 0;
		}

		// 최대 체력을 넘긴 경우
		if (answer >= health)
			answer = health;

		// 체력이 0 이하가 된 경우
		if (answer <= 0) {
			answer = -1;
			break;
		}
	}

	return answer;
}