#include <vector>
#include <map>

using namespace std;

map<long long, long long> room_map;		// first : 배정된 방 번호, second : 다음 고객이 찾을 때 그 다음 가능한 방 번호

long long findAvailableRoomNum(long long num) {
	// 만약 아직 배정된 방이 아니라면
	if (room_map[num] == 0)
		return num;
	else {
		// 이미 배정되었다면 다음으로 
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