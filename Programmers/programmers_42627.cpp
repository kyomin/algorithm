#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Disk {
	int request_time;	// 요청 시간
	int task_time;		// 작업 시간
};

// 요청 시간에 대한 오름차순 정렬
bool cmp1(const Disk &disk1, const Disk &disk2) {
	if (disk1.request_time < disk2.request_time)
		return true;
	else
		return false;
}

// 작업 시간에 대한 오름차순 정렬
struct cmp2 {
	bool operator()(Disk disk1, Disk disk2) {
		return (disk1.task_time > disk2.task_time);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int idx = 0;
	int time = 0;
	int len = jobs.size();

	vector<Disk> disks;
	
	for (int i = 0; i < len; i++)
		disks.push_back({ jobs[i][0], jobs[i][1] });

	sort(disks.begin(), disks.end(), cmp1);

	priority_queue<Disk, vector<Disk>, cmp2> pq;

	while (idx < disks.size() || !pq.empty()) {
		// 현 경과 시간보다 요청 시간이 작거나 같은 경우에 pq에 삽입!
		if (disks.size() > idx && time >= disks[idx].request_time) {
			pq.push(disks[idx]);
			idx++;
			continue;
		}

		if (!pq.empty()) {
			time += pq.top().task_time;
			answer += time - pq.top().request_time;
			pq.pop();
		}
		else
			time = disks[idx].request_time;
	}

	return answer / disks.size();
}