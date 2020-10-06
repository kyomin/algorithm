#include <vector>
#include <map>

using namespace std;

map<long long, long long> room_map;		// first : ������ �� ��ȣ, second : ���� ���� ã�� �� �� ���� ������ �� ��ȣ

long long findAvailableRoomNum(long long num) {
	// ���� ���� ������ ���� �ƴ϶��
	if (room_map[num] == 0)
		return num;
	else {
		// �̹� �����Ǿ��ٸ� �������� 
		room_map[num] = findAvailableRoomNum(room_map[num]);
		return room_map[num];
	}
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	long long roomN;
	long long otherRoomN;
	int len = room_number.size();

	for (int i = 0; i < len; i++) {
		roomN = room_number[i];

		if (room_map[roomN] == 0) {
			answer.push_back(roomN);
			room_map[roomN] = findAvailableRoomNum(roomN + 1);
		}
		else {
			otherRoomN = findAvailableRoomNum(roomN);
			answer.push_back(otherRoomN);
			room_map[otherRoomN] = findAvailableRoomNum(otherRoomN + 1);
		}
	}

	return answer;
}