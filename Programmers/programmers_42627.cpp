#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Disk {
	int request_time;	// ��û �ð�
	int task_time;		// �۾� �ð�
};

// ��û �ð��� ���� �������� ����
bool cmp1(const Disk &disk1, const Disk &disk2) {
	if (disk1.request_time < disk2.request_time)
		return true;
	else
		return false;
}

// �۾� �ð��� ���� �������� ����
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
		// �� ��� �ð����� ��û �ð��� �۰ų� ���� ��쿡 pq�� ����!
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